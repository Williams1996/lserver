#include "HttpResponse.h"
#include "http.h"

const map<int,string> HttpResponse::StatusCode2Reason{
	{200,"OK"},
	{404,"Not Found"}};


HttpResponse::HttpResponse():StatusCode(200),version("HTTP/1.1"){
    ;
}

string HttpResponse::str(){
	string ret;
	ret += header();
	ret += string("Content-length: ") + to_string(content.size()) + crlf;
	ret += string("Content-type:") + ContentType + crlf;
	ret += crlf;
	return ret;
}

string HttpResponse::header(){
	string ret;
	ret = version + " " + to_string(StatusCode) + " " + StatusCode2Reason.at(StatusCode) + crlf;
	return ret;
}

void HttpResponse::setContent(ByteBuffer buffer){
	content = move(buffer);
}

ByteBuffer HttpResponse::getContent(){
	return move(content);
}

void HttpResponse::setContentType(string type){
	ContentType = type;
}

string HttpResponse::getContentType(){
	return ContentType;
}