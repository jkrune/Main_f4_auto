#include "move.h"

void chienthuat_1(void)
{
	///0
//	run_foward_steps(Fast_speed, 1000);

	run_foward_count(Basic_speed, 1 , 0);
	//1
	run_foward_steps(Fast_speed, 1000);

	run_foward_count(Basic_speed, 2 , 0);
	//2
	cho_lenh(1);

	run_foward_steps(Basic_speed, 1);//chay doan nho den gan con doc

	nang_ha_led(nang);

	chay_doc(len_doc_speed,tien,1000);//len doc

	bat_den(on);

	cho_lenh(2);

	chay_doc(xuong_doc_speed,lui,1000);//xuong doc

	bat_den(off);

	nang_ha_led(ha);//ha led

//	run_foward_steps(Fast_speed, 1000);
//
//	run_foward_count(Basic_speed, 3 , 0);
//	//3
//	run_foward_steps(Fast_speed, 1000);

	run_foward_count(Basic_speed, 4 , 0);
	//4
//	run_right_steps(Fast_speed, 1000);

	cho_lenh(1);

	nang_ha_led(nang);

	chay_doc(len_doc_speed,phai,1000);//len doc phai

	bat_den(on);

	cho_lenh(2);

	chay_doc(xuong_doc_speed,phai,1000);//xuong doc

	bat_den(off);

	nang_ha_led(ha);//ha led

//	run_right_steps(Fast_speed, 1000);

	run_rightside_count(Basic_speed, 5 , 0);
	//5

	run_backward_steps(Basic_speed, 1000);

	run_backward_count(Basic_speed, 0 , 1);
	//nga4-1
//	run_backward_steps(Basic_speed, 1000);

	cho_lenh(1);

	nang_ha_led(nang);

	chay_doc(len_doc_speed,lui,1000);

	bat_den(on);

	cho_lenh(2);

	chay_doc(xuong_doc_speed,tien,1000);

	bat_den(off);

	run_foward_steps(Basic_speed, 1000);

	run_foward_count(Basic_speed, 0 , 2);
	//nga4-2
	run_right_steps(Basic_speed, 1000);

	chay_doc(len_doc_speed, phai, 1000);

	//cho lenh ban bong
	//done!!
	//while(1);
}
