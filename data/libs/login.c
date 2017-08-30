/*Correlation comment - Do not change!  Original value='121826.579100851zczztftpzzcfDHfQipHcHQHf' Name ='userSession' Type ='ResponseBased'*/
web_reg_save_param_regexp(
	"ParamName=userSession",
	"RegExp=name=\"userSession\"\\ value=\"(.*?)\"/>\\\n<table\\ border",
	SEARCH_FILTERS,
	"Scope=Body",
	"IgnoreRedirections=No",
	"RequestUrl=*/nav.pl*",
	LAST);

web_url("WebTours", 
	"URL={url}WebTours", 
	"TargetFrame=", 
	"Resource=0", 
	"RecContentType=text/html", 
	"Referer=", 
	"Snapshot=t17.inf", 
	"Mode=HTML", 
	LAST);

web_url("header.html", 
	"URL={url}WebTours/header.html", 
	"TargetFrame=", 
	"Resource=0", 
	"RecContentType=text/html", 
	"Snapshot=t18.inf", 
	"Mode=HTML", 
	LAST);