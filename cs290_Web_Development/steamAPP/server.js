var key='36C7317060D35A8F3407E9A04C36D24F';
var steamID='76561198097834797';
//http://steamcommunity.com/profiles/76561198097834797/home
//http://steamcommunity.com/profiles/76561198097834797/home
var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var request = require ('request');

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3000);

/*
app.get('/',function(req,res){
  res.render('home');
});
*/

app.get('/', function(httpRequest, httpResponse) {
    //var url = 'http://api.steampowered.com/ISteamUserStats/GetSchemaForGame/' +'v2/?key='+key+'&appid=6';
    //var url='http://api.steampowered.com/ISteamNews/GetNewsForApp/v0002/?appid=440&count=3&maxlength=300&format=json';
	var url='http://api.steampowered.com/ISteamUserStats/GetPlayerAchievements/v0001/?appid=22380&key='+key+'&steamid='+steamID;
	//var url=' http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key='+ key+'&steamids='+steamID;
	request.get(url, function(error, steamHttpResponse, steamHttpBody) {

		function playerstats(id, gName, pAchievement) {
			this.steamID = id;
			this.gameName = gName;
			this.achievements = pAchievement.slice();
		}
		var finalObj = new playerstats(
		JSON.parse( steamHttpBody ).playerstats.steamID, 
		JSON.parse( steamHttpBody ).playerstats.gameName, 
		JSON.parse( steamHttpBody ).playerstats.achievements
		);

		//console.log(finalObj.achievements);
		httpResponse.render('home', {finalObj});   
    });
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});