var express = require('express');
var mysql = require('mysql');
//login to database
var pool = mysql.createPool({
    host  : 'classmysql.engr.oregonstate.edu',
    user  : 'cs290_shadidk',
    password: '3818',
    database: 'cs290_shadidk',
    dateStrings: 'true'
});

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port',20767);
app.use(express.static('public'));

app.get('/', function(req, res, next){
	
    // get from database 
	pool.query('SELECT * FROM workouts', function(err, rows, fields){
		
	if(err){
		next(err);
		return;
	}
	
	var array = [];

	
	//store row in array
	for(var x in rows){
		
		var rowValue = {
			'name': rows[x].name, 
			'reps': rows[x].reps, 
			'weight': rows[x].weight, 
			'date':rows[x].date, 
			'id':rows[x].id
		};
					
		if(rows[x].lbs){
			rowValue.lbs = "LBS";
		}
		else{
			rowValue.lbs = "KG";
		}
		
		array.push(rowValue);
		
	}
	var output = {};
	output.results = array;
	//convert to JSON and Send	
	res.render('home', output);
	})
});



app.get('/insert',function(req,res,next){
  
	// create the query
	pool.query("INSERT INTO `workouts` (`name`, `reps`, `weight`, `date`, `lbs`) VALUES (?, ?, ?, ?, ?)", 
	[req.query.exercise, 
	req.query.reps, 
	req.query.weight, 
	req.query.date, 
	req.query.units], 
	function(err, result){
		if(err){
			next(err);
			return;
		}
		
		
	var output = {};		
	output.inserted = result.insertId;
	//convert to JSON and Send
	res.send(JSON.stringify(output));
	});
});
app.get('/edit',function(req, res, next){
    // check for a match with UniqueIDs in database
	pool.query('SELECT * FROM `workouts` WHERE id=?',
		[req.query.id], 
		function(err, rows, fields){
			if(err){
				next(err);
				return;
			}
			var array = [];

			for(var x in rows){
				var rowValue = {
					'name': rows[x].name, 
					'reps': rows[x].reps, 
					'weight': rows[x].weight, 
					'date':rows[x].date, 
					'lbs':rows[x].lbs,
					'id':rows[x].id
				};

                array.push(rowValue);
            }
			
        var output = {};
        output.results = array[0];
        res.render('edit', output);
    });
});
// The delete get handler
app.get('/delete', function(req, res, next) {
	
    // check for a match with UniqueIDs in database
	pool.query("DELETE FROM `workouts` WHERE id = ?", 
		[req.query.id], 
		function(err, result) {
			if(err){
				next(err);
				return;
			}
	});
});



app.get('/editDone', function(req, res, next){
	var context = {};


	pool.query("SELECT * FROM `workouts` WHERE id=?", 
		[req.query.id], 
		function(err, result){
			if(err){
				next(err);
				return;
			}
			if(result.length == 1){
                // get the current values from the database
				var curVals = result[0];

                // set up the checkbox for the table
				if(req.query.units === "on"){
					req.query.units = "1";
				}
				else{
					req.query.units = "0";
				}

				pool.query('UPDATE `workouts` SET name=?, reps=?, weight=?, date=?, lbs=? WHERE id=?', 
				[req.query.exercise || curVals.name, 
				req.query.reps || curVals.reps, 
				req.query.weight || curVals.weight, 
				req.query.date || curVals.date, 
				req.query.units, 
				req.query.id],
				function(err, result){
					if(err){
						next(err);
						return;
					}


					pool.query('SELECT * FROM `workouts`', function(err, rows, fields){
						if(err){
							next(err);
							return;
						}
						var array = [];

						for(var x in rows){
							var toPush = {'name': rows[x].name, 
							'reps': rows[x].reps,
							'weight': rows[x].weight, 
							'date':rows[x].date, 
							'id':rows[x].id};

							if(rows[x].lbs){
								toPush.lbs = "LBS";
							}
							else{
								toPush.lbs = "KG";
							}
							array.push(toPush);
						}

						context.results = array;
						res.render('home', context);
					});
				});
			}
	});
});


// show table Code provided
app.get('/reset-table',function(req,res,next){
	var context = {};
	pool.query("DROP TABLE IF EXISTS workouts", function(err){
		var createString = "CREATE TABLE workouts("+
		"id INT PRIMARY KEY AUTO_INCREMENT,"+
		"name VARCHAR(255) NOT NULL,"+
		"reps INT,"+
		"weight INT,"+
		"date DATE,"+
		"lbs BOOLEAN)";
		pool.query(createString, function(err){
            res.render('home',context);
        })
    });
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
