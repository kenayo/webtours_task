vuser_init()
{
	/* ------------------------------------------------------------------------------- 
	Script Title: webtours_UC02_cashier_both_ways
	Script Description:†скрипт авторизуетс€ на сайте заказа билетов, выполн€ет 
	несколько операций по их покупке, после чего с сайта выходит.
	------------------------------------------------------------------------------- */
	/* ѕеременна€ дл€ хранени€ ip-адреса вузера */
	char *client_ip;
	
	lr_save_string("webtour_02_загрузка_страницы", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	
	#include "../../data/libs/login.c"
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);

	lr_save_string("webtour_02_авторизаци€", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	
	#include "../../data/libs/loginFP.c"
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);
	
	/* «аписать ip-адрес вузера и сообщить его.
	 ≈сли ip-адреса нет, тоже сообщить об этом.*/
	client_ip = lr_get_vuser_ip();
	if (client_ip)
	     lr_output_message("ip-адрес: %s", client_ip);
	else
	     lr_output_message("ip-адрес не найден");
	
	return 0;
}
