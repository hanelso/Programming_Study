
var http = require("http");

var server = http.createServer();

var port = 3000;
server.listen(port, function() {
	console.log(" starting web. : %d", port);
});

server.on("connection", function(socket) {
	var addr = socket.address();
	console.log(" connecting client. : %s %d", addr.address, addr.port);
});

server.on("request", function(req, res) {
	console.log(" client requrest.");
	console.dir(req);
});

server.on("close", function() {
	console.log(" close server ");
});
