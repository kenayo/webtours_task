main_action()
{
	/* две переменные для генерации случайных чисел в параметрах дат */
	int depart_date_offset;
	int return_date_offset;
	
	lr_start_transaction("webtour_UC01_покупка_билета_в_одну_сторону");
	
	lr_save_string("webtour_01_01_выбор_рейса", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	
	web_url("Search Flights Button", 
		"URL={url}cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);
	
	/* Сгенерить для двух пар-ов depart_city и arrive_city случайные значение из списка городов */
	lr_save_string(lr_eval_string("{random_city}"), "depart_city");
	lr_save_string(lr_eval_string("{random_city}"), "arrive_city");
	
	/* Запускаем цикл, который будет генерить для arrive_city новые значения, пока depart_city и arrive_city не станут разными */
	while (strcmp(lr_eval_string("{depart_city}"), lr_eval_string("{arrive_city}"))  == 0) {
		lr_save_string(lr_eval_string("{random_city}"), "arrive_city");
	}
	
	/* Создаем параметр для даты вылета (туда):
	сегодня + случайное число дней от 1 до 5 */
	depart_date_offset = 60 * 60 * 24 * ((rand() % 5) + 1);
	lr_save_datetime("%m/%d/%y", depart_date_offset, "depart_date");
	
	/* Создаем параметр для даты вылета (обратно):
	дата вылета из предыдущей переменной + случайное число дней от 1 до 5 */
	return_date_offset = depart_date_offset + 60 * 60 * 24 * ((rand() % 5) + 1);
	lr_save_datetime("%m/%d/%y", return_date_offset, "return_date");
	
	/* Создать массив outbound_flight_array с данными для формы 2 */
	web_reg_save_param(
		"outbound_flight_array",
		"LB=<input type=\"radio\" name=\"outboundFlight\" value=\"",
		"RB=\"",
		"ORD=All",
		LAST);
	
	lr_save_string("webtour_01_02_выбор_параметров_билета", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));

	web_submit_data("reservations.pl", 
		"Action={url}cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart_city}", ENDITEM, 
		"Name=departDate", "Value={depart_date}", ENDITEM,
		"Name=arrive", "Value={arrive_city}", ENDITEM, 
		"Name=returnDate", "Value={return_date}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seat_pref}", ENDITEM, 
		"Name=seatType", "Value={seat_type}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=79", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);
	
	lr_save_string(lr_paramarr_random("outbound_flight_array"), "outbound_flight");
	
	lr_save_string("webtour_01_03_выбор_времени_вылета", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));

	web_submit_data("reservations.pl_2",
		"Action={url}cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t22.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outbound_flight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seat_type}", ENDITEM,
		"Name=seatPref", "Value={seat_pref}", ENDITEM,
		"Name=reserveFlights.x", "Value=60", ENDITEM,
		"Name=reserveFlights.y", "Value=7", ENDITEM,
		LAST);

	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);
	
	lr_save_string("webtour_01_04_ввод_платежных_данных", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));

	web_submit_data("reservations.pl_3",
		"Action={url}cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Snapshot=t23.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={first_name}", ENDITEM,
		"Name=lastName", "Value={last_name}", ENDITEM,
		"Name=address1", "Value={address}", ENDITEM,
		"Name=address2", "Value=", ENDITEM,
		"Name=pass1", "Value={first_name} {last_name}", ENDITEM,
		"Name=creditCard", "Value={credit_card_num}", ENDITEM,
		"Name=expDate", "Value={credit_card_exp_date}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seat_type}", ENDITEM,
		"Name=seatPref", "Value={seat_pref}", ENDITEM,
		"Name=outboundFlight", "Value={outbound_flight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=40", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		LAST);
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);
	
	lr_end_transaction("webtour_UC01_покупка_билета_в_одну_сторону", LR_AUTO);
	
	return 0;
}
