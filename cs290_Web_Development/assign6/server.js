'use strict';

var express = require('express');
var bodyParser = require('body-parser');

var handlebars = require('express-handlebars').create({defaultLayout: 'main'});

var app = express();

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.use(function(req, res, next) {
	
    console.log('Passed Parametrs: ', req.body)
    next();
});

app.get('/', function (req, res) {


	res.render('get', req.body);
	    console.log('get request');

  //  res.render('home');
});
app.post('/', function(req, res){


		res.render('post', req.body);

		    console.log('post request');

});
app.use(function(req, res){
console.log('404');

		res.status(404);
		res.render('404');
});

app.use(function(err, req, res, next){
	console.log('500');

	console.log(err.stack);
	res.status(500);
	
	res.render('500');
});
app.listen(20769, function () {
    console.log('Running on port: 3000');
});