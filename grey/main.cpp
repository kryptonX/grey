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

#include <iostream>
#include <stdio.h>
#include "comm.h"
#include <cstring>

using namespace std;


int main(int argc, char* argv[2]) {
		if(argc < 2) {
		std::cout << "grey is based off syringe-irecovery and uses iRecovery to talk to the iBoot\nOpensource @ github.com/kryptonX/grey\n";			
		std::cout << "./args\n\n-a\t\tstart the act console\n";
		std::cout << "-ab\t\tSet autoboot to true\n";
		std::cout << "-b\t\tGrab BOARD ID\n";
		std::cout << "-c <command>\tSend a command\n";
		std::cout << "-m\t\tGrab mode";
		return 0;
	}
			else {

	char** pArg;
	for (pArg = argv + 1; pArg < argv + argc; ++pArg) {
	const char* arg = *pArg;
		int* pIntOpt = NULL;
	if (!strcmp(arg, "-a")) {
		_act_();
	} else if (!strcmp(arg, "-b")) {
		_bdid_();
	} else if (!strcmp(arg, "-c")) {
	_command_(argv[2]);
	}
	 else if (!strcmp(arg, "-m")) {
		if ((_mode_()) == 1) {
			std::cout << "\nRecoverymode\n";
		} else if ((_mode_()) == 2) {std::cout << "\ndfu";} else {cout <<"\n";}
	} else if (!strcmp(arg, "-ab")) {
		_autoboot_();
	 }

}

			}

}