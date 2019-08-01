var http = require("http");

// 보낼 요청의 패킷 정보를 설정
var opts = {
	host : "www.google.com",
	port : 80,
	method : "POST",
	path : "/",
	headers : {}
};

var resData = "";

// post 요청을 opts설정으로 진행한다.
var req = http.request( opts, function(res) {
	// 응답 처리 
	res.on("data", function(chunk) {
		resData += chunk;
	});

	res.on("end", function() {
		console.log(resData);
	});
});

// POST요청을 보내는 패킷의 http통신 레더를 설정한다.
opts.headers['Content-Type'] = 'application/x-www-form-urlencoded';
req.data = "q=actor";
opts.headers['Content-Length'] = req.data.length;

req.on("error", function(err) {
	console.log("오류 발생 : ", err.message);
});

// 요청 전송
req.write( req.data );
req.end();

