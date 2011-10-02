/**
  * Advanced modules for syringe based iRecovery
  * Copyright (C) 2011 KryptonX
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/



#include "comm.h"
#include "../s-irecovery/include/libirecovery.h"
#include "../s-irecovery/include/libpois0n.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int _act_(void) {
	int s_ret = 0;
	int ram = 0;
	s_ret = irecv_open_attempts(&client, 10);	/* Open attempts and load client */
	irecv_send_command(client, "sanneev");	/* Send commmand {s_cmd[2]} */
	irecv_exit();	/* kill & clear client */
		 srand ( time(NULL) );
		 _command_("fsck_hfs");
		 _command_("fsck -f reset");
		 _command_("reset");
	return s_ret;
}

int _bdid_() {
	irecv_init();
	//irecv_open_attempts(&client, 10);
	std::cout << device->board_id;
	irecv_exit();
	return 0;
}

int _command_(const char* s_cmd) {
	int s_ret = 0;	/*Value to be returned */
	s_ret = irecv_open_attempts(&client, 10);	/* Open attempts and load client */
	irecv_send_command(client, s_cmd);	/* Send commmand {s_cmd[2]} */
	irecv_exit();	/* kill & clear client */
	return s_ret;		/* Return ret */
}

void _file_(const char* s_file) {
	irecv_open_attempts(&client, 10);	
	if(client->mode == kDfuMode) {		
		irecv_send_file(client, s_file,1);
	}	else {
		
	irecv_send_file(client, s_file,0);
		}
		irecv_exit();
}

int recv_vars(const char* s_var) {
	int s_ret = -2;	/* Return Variable */
	irecv_open_attempts(&client, 10);
		if (client->mode == kRecoveryMode1 || client->mode == kRecoveryMode2 || client->mode == kRecoveryMode3 || client->mode == kRecoveryMode4) {
			_mode_();
			s_ret = _command_("3");
			return s_ret;
		} else if (client->mode == kDfuMode) {
			_mode_();
			s_ret = _command_("2");
			return s_ret;
		} else return (-1);	
}

int _mode_() {	
	/*	* 0 == No Device
		* 1 == Recovery Mode
		* 2 == DFU
		* EOF (-1) == Unknown device && mode (won't happen anyways)
	*/
	int _mod = 0;
	irecv_open_attempts(&client, 10);
	if (client->mode == kDfuMode) {_mod = 2;} 
	else if (client->mode == kRecoveryMode1 || client->mode == kRecoveryMode2 || client->mode == kRecoveryMode3 || client->mode == kRecoveryMode4) 
	{_mod = 1;}
	else if (client->mode == NULL) {_mod = 0;}
	else if (client->mode == NULL && device->chip_id == CPID_UNKNOWN) {return EOF;}
	else {return EOF;}
	return _mod;
}

int _call_(const char* _input_) {
	return 0;
}

void _autoboot_() {
	_command_("reset");
}

