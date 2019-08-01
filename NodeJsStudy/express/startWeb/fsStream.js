var fs = require("fs");
var http = require("http");

var server = http.createServer(function( req, res) {
	console.log("client requesting");

	var filename = "/home/pi/.viminfo";
	var infile = fs.createReadStream(filename, { flag : 'r' } );

	// 파이프로 연결하여 알아서 처리한다.
	infile.pipe(res);
});

var port = 3000;
server.listen(port, function() {
	console.log(" starting web. : %d", port);
});

server.on("connection", function(socket) {
	var addr = socket.address();
	console.log(" connecting client. : %s %d", addr.address, addr.port);
});


server.on("close", function() {
	console.log(" close server ");
});
