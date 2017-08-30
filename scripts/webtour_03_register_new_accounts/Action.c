Action()
{
	web_url("login.pl", 
		"URL={url}cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("login.pl_2", 
		"Action={url}cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=62", ENDITEM, 
		"Name=register.y", "Value=9", ENDITEM, 
		LAST);
	
	return 0;
}