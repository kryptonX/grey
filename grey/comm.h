#ifndef comm_H
#define comm_H

#include "../s-irecovery/include/libirecovery.h"

int _act_(void);
int _bdid_();
int _command_(const char* s_cmd);
void _file_(const char* s_file);
int recv_vars(const char* s_var);
int _mode_();
void _autoboot_();
#endif