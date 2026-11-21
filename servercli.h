#ifndef SERVERCLI_H_INCLUDED
#define SERVERCLI_H_INCLUDED


#include "cli.h"
#include "ftpserver.h"
#include <windows.h>

class ServerCLI : public CmdLineInterface
{
private:
    FTPServer* ftp;
public:
    ServerCLI();
    ~ServerCLI();
protected:
    virtual void initCmd();
private:
    void doStart(char * cmd_argv[], int cmd_argc);
    void doStop(char * cmd_argv[], int cmd_argc);
    void doStatus(char * cmd_argv[], int cmd_argc);
    void doRestart(char * cmd_argv[], int cmd_argc);
    void doHelp(char * cmd_argv[], int cmd_argc);
};

#endif // SERVERCLI_H_INCLUDED
