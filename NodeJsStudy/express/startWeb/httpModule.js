
var http = require("http");

// make server object
var server = http.createServer();

// start web server
var host = "192.168.99.14";
var port = 3000;

server.listen(port,host, function() {
	console.log(" starting Web server : %s %d", host,  port);
});
