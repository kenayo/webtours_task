printing_parametres()
{
	lr_output_message("userSession: %s", lr_eval_string("{userSession}"));
	lr_output_message("outbound_flight: %s", lr_eval_string("{outbound_flight}"));
	lr_output_message("outbound_flight: %s", lr_eval_string("{return_flight}"));
	lr_output_message("first_name: %s", lr_eval_string("{first_name}"));
	lr_output_message("last_name: %s", lr_eval_string("{last_name}"));
	lr_output_message("address: %s", lr_eval_string("{address}"));
	lr_output_message("credit_card_num: %s", lr_eval_string("{credit_card_num}"));
	lr_output_message("credit_card_exp_date: %s", lr_eval_string("{credit_card_exp_date}"));
	lr_output_message("seat_type: %s", lr_eval_string("{seat_type}"));
	lr_output_message("seat_pref: %s", lr_eval_string("{seat_pref}"));
	lr_output_message("url: %s", lr_eval_string("{url}"));
	lr_output_message("depart_city: %s", lr_eval_string("{depart_city}"));
	lr_output_message("depart_date: %s", lr_eval_string("{depart_date}"));
	lr_output_message("arrive_city: %s", lr_eval_string("{arrive_city}"));
	lr_output_message("return_date: %s", lr_eval_string("{return_date}"));
	
	return 0;
}
