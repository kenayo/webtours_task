vuser_end()
{
	lr_save_string("webtour_01_выход_с_аккаунта", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	
	#include "../../data/libs/logout.c"
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);

	return 0;
}
