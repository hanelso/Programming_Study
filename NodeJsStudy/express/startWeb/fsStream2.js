// fsStream.js의 경우 스트림을 사용하지만 헤더를 넣지 못한다는 단점이있다.
// 이번에는 스트림을 사용하되 부분만을 보내는 방법을 생각해보자


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

server.on("request", function(req, res) {
	console.log("client requesting");

	var filename = "/home/pi/.viminfo";
	var infile = fs.createReadStream( filename, { flag : 'r' } );
	var filelength = 0;
	var curlength = 0;

	fs.stat( filename ,function(err, stats) {
		filelength = stats.size;
	});

	// 헤더 쓰기
	res.writeHead(200, {"Content-Type":"plain/text"});

	// 파일 내용을 스트림에서 읽어 본문 쓰기
	infile.on("readable", function() {
		var chunk;
		while(null!== (chunk = infile.read())){

			console.log("읽어 들인 데이터 크기 : %d 바이트", chunk.length);
			curlength += chunk.length;
			res.write(chunk, "utf8", function(err) {
				console.log("파일 부분 쓰기 완료 : %d, 파일 크기 : %d", curlength, filelength );
				if( curlength >=filelength)
				{
					// 응답 전송
					res.end();
				}
			});
		}
	});
});

server.on("connection", function(socket) {
	var addr = socket.address();
	console.log(" connecting client. : %s %d", addr.address, addr.port);
});


server.on("close", function() {
	console.log(" close server ");
});
