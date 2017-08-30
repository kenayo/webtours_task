check()
{
	/*Example to look for: 
	08/31/17
	 :  1pm : Flight 801 leaves Sydney  for Denver.<br>  </center>*/

	/* Ищем приобретенные билеты на странице купленных билетов */
	web_reg_find("TextPfx={depart_date}", 
	             "TextSfx= leaves {depart_city}  for {arrive_city}\.",
				 LAST);
	
	web_reg_find("TextPfx={return_date}", 
	             "TextSfx= leaves {arrive_city}  for {depart_city}\.",
				 LAST);

	web_url("Itinerary", 
		"URL={url}cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}