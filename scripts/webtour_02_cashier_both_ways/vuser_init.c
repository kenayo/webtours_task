vuser_init()
{
	/* ------------------------------------------------------------------------------- 
	Script Title: webtours_UC02_cashier_both_ways
	Script Description:������� ������������ �� ����� ������ �������, ��������� 
	��������� �������� �� �� �������, ����� ���� � ����� �������.
	------------------------------------------------------------------------------- */
	/* ���������� ��� �������� ip-������ ������ */
	char *client_ip;
	
	lr_save_string("webtour_02_��������_��������", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	
	#include "../../data/libs/login.c"
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);

	lr_save_string("webtour_02_�����������", "transaction_name");
	lr_start_transaction(lr_eval_string("{transaction_name}"));
	lr_output_message(lr_eval_string("Start transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	
	#include "../../data/libs/loginFP.c"
	
	lr_output_message(lr_eval_string("End transaction \"{transaction_name}\" at: %s"), lr_eval_string("{time}"));
	lr_end_transaction(lr_eval_string("{transaction_name}"), LR_AUTO);
	
	/* �������� ip-����� ������ � �������� ���.
	 ���� ip-������ ���, ���� �������� �� ����.*/
	client_ip = lr_get_vuser_ip();
	if (client_ip)
	     lr_output_message("ip-�����: %s", client_ip);
	else
	     lr_output_message("ip-����� �� ������");
	
	return 0;
}
