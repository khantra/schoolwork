/*
*alternative to jquery $(Document).ready () http://stackoverflow.com/questions/9899372/pure-javascript-equivalent-to-jquerys-ready-how-to-call-a-function-when-the
*https://developer.mozilla.org/en-US/docs/Web/Events/DOMContentLoaded
*https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/Using_XMLHttpRequest
*HTTp Status check https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/status
*Status codes https://developer.mozilla.org/en-US/docs/Web/HTTP/Status

*/

	//'load' doesn't work for document. Jquery Document.ready()..
	document.addEventListener('DOMContentLoaded', function() {
	document.getElementById('weatherBTN').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		
		
		var url = "http://api.openweathermap.org/data/2.5/weather?";
		var appID = "&appid=fa7d80c48643dfadde2cced1b1be6ca1";
		var cityInput = document.getElementById("cityInput").value;
		var zipInput = document.getElementById("zipInput").value;
		var userInput;
		//validation
		if (zipInput  && cityInput=="" || (zipInput  && cityInput)) 
			userInput = "zip=" + zipInput;
		else if(zipInput=="" && cityInput )
			userInput = "q=" + cityInput;	
		else if(zipInput=="" && cityInput=="")
			alert("Please Enter Zip Code or City");


		
		var reqAddress = url + userInput + appID + '&units=imperial';
		
		
		
		req.open("GET", reqAddress, true);
		//use event handler for when request is being loaded
		console.log(req.status );	//status must be greated than = to 200( 'ok' through 'redirected') and less than 400 (bad request)  
		req.addEventListener('load', function() {
		if (req.status >= 200 && req.status < 400) {
			console.log(JSON.parse(req.responseText));
			var res = JSON.parse(req.responseText);
			//console.log(res);			
			document.getElementById("cityGroup").classList.remove("hidden");
			document.getElementById('city').textContent ="Todays Forecast for the great city of "+ res.name+"!";
			document.getElementById('weatherDesc').textContent = res.weather[0].description ;
			document.getElementById('Wind').textContent = res.wind.speed ;
			document.getElementById('humidity').textContent = res.main.humidity;
			document.getElementById('temp').textContent = res.main.temp;
			console.log(res);
			} 
		else {
			var error = "Problem with Call. Status code["+  req.status+"]: "+ res.statusText;
			console.log(error);
		}

		});
		req.send();
		event.preventDefault();
	});

	document.getElementById('pasteSubmit').addEventListener('click', function(e){
		var req = new XMLHttpRequest();
		var url = "http://httpbin.org/post";
		var payload = {
			'name': null,
			'age': null,
			'weight': null
		};
		payload.name = document.getElementById('userName').value;
		payload.age = document.getElementById('userAge').value;
		payload.weight = document.getElementById('userGender').value;
		req.open("POST", url, true);
		req.setRequestHeader('Content-Type', 'application/json');

		console.log(req.status );	//status must be greated than = to 200( 'ok' through 'redirected') and less than 400 (bad request)  
		
		req.addEventListener('load', function() {
			if (req.status >= 200 && req.status < 400) {
				console.log(JSON.parse(req.responseText));
				var res = JSON.parse(JSON.parse(req.responseText).data);
				console.log(res);
				document.getElementById('recievedGender').textContent = res.weight;
				document.getElementById('recievedName').textContent = res.name;
				document.getElementById('recievedAge').textContent = res.age;
			} else {
			var error = "Problem with Call. Status code["+  req.status+"]: "+ res.statusText;
			console.log(error);
			}
		});
		req.send(JSON.stringify(payload));
		e.preventDefault();
	});
});





