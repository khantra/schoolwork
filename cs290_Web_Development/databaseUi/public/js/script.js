document.getElementById('addItemSubmit').addEventListener('click',function(event){
	
	// get the form id
	var addExercise = document.getElementById("insertForm");

	// create a request so that we can add the element to the server
	var req = new XMLHttpRequest();

	// craft request like API request
	var sqlCommand = "/insert"; 
	var parameters = "exercise="+addExercise.elements.exercise.value+"&reps="+addExercise.elements.reps.value+
					"&weight="+addExercise.elements.weight.value+"&date="+addExercise.elements.date.value;
	// console.log(parameters);
	
	if(addExercise.elements.units.checked){
		parameters+="&units=1";
	}
	else{
		parameters+="&units=0";
	}

	// make the request
	
	req.open("GET", sqlCommand +"?"+parameters, true);
	req.setRequestHeader('Content-Type','application/x-www-form-urlencoded');

	req.addEventListener('load', function(){
		if(req.status >= 200 && req.status < 400){

			// Converst to JSON
			var response = JSON.parse(req.responseText);
			var id = response.inserted;
			var table = document.getElementById("exerciseTable");
			var row = table.insertRow(-1);

			var cell = document.createElement('td');
			cell.textContent = addExercise.elements.exercise.value;
			row.appendChild(cell);

			var reps = document.createElement('td');
			reps.textContent = addExercise.elements.reps.value;
			row.appendChild(reps);

			var weight = document.createElement('td');
			weight.textContent = addExercise.elements.weight.value;
			row.appendChild(weight);

			// if they checked the LBS checkbox, then set the text content to LBS
			// otherwise set it to KG, then create the cell
			var measurementCell = document.createElement('td');
			if(addExercise.elements.units.checked){
				measurementCell.textContent = "LBS"
			}
			else{
				measurementCell.textContent = "KG"
			}
			row.appendChild(measurementCell);

			var date = document.createElement('td');
			
				date.textContent = addExercise.elements.date.value;
		row.appendChild(date);


			var cell = document.createElement('td');
			var linkAddress = document.createElement('a');
			
		linkAddress.setAttribute('href','/edit?id='+id);
			
			var tempButton = document.createElement('input');
			
			
		tempButton.setAttribute('type','button');
			tempButton.setAttribute('value','edit');
			linkAddress.appendChild(tempButton);
			
		cell.appendChild(linkAddress);
			row.appendChild(cell);


            var cellTwo = document.createElement('td');
            var deleteButtonTwo = document.createElement('input');
            deleteButtonTwo.setAttribute('type', 'button');
            deleteButtonTwo.setAttribute('name', 'delete');
			
            deleteButtonTwo.setAttribute('value', 'Delete');
            deleteButtonTwo.setAttribute('onClick', 'deleteRow("dataTable",' + id + ')');
			
			
            var deleteHidden = document.createElement('input');
			
            deleteHidden.setAttribute('type', 'hidden');
            deleteHidden.setAttribute('id', 'delete' + id);
			
            cellTwo.appendChild(deleteButtonTwo);
            cellTwo.appendChild(deleteHidden);
            row.appendChild(cellTwo);


        }
        else {
            console.log('there was an error');
        }
    });

    // send request
    req.send(sqlCommand + "?" + parameters);
    event.preventDefault();
});

function deleteRow(tableId, id) {
    // get the table and row count
    var table = document.getElementById(tableId);
    var count = table.rows.length;

    // create a matching id for the hidden id
    var deleteString = "delete" + id;

    for (var i = 1; i < count; i++) {
        var row = table.rows[i];
        var dataCells = row.getElementsByTagName("td");
        var cellTwo = dataCells[dataCells.length - 1];
		
        if (cellTwo.children[1].id === deleteString) {

			table.deleteRow(i);
        }

    }

    // setup and send a delete request to the server so it can delete the entry
    // from the database
    var req = new XMLHttpRequest();
    var sqlCommand = "/delete";

    req.open("GET", sqlCommand + "?id=" + id, true);

    req.addEventListener("load", function () {
        if (req.status >= 200 && req.status < 400) {
            console.log('delete request sent');
        } else {
            console.log('there was an error');
        }
    });

    req.send(sqlCommand + "?id=" + id);

}