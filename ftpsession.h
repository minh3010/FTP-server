#ifndef FTPSESSION_H_INCLUDED
#define FTPSESSION_H_INCLUDED
#include <vector>
#include "tcpserversocket.h"
#include "session.h"
#include "ftpserverconfig.h"
#include <cstdint>
// #define STATUS_INIT     0
// #define STATUS_FROM     1
// #define STATUS_TO       2


// cac lenh trong ban tin FTP request
#define USER  "USER"
#define PASS  "PASS"
#define QUIT  "QUIT"
#define PASV  "PASV"
#define STOR  "STOR"
#define DELE  "DELE"
#define MKD   "MKD"
#define CWD   "CWD"
#define LIST  "LIST"

#ifndef QUIT
    #define QUIT  "QUIT"
#endif // QUIT


struct FTPSessionInfo
{
    //uint8_t  status;
    string username;
    string currDir="/";
    bool loggedIn;
};

class FTPSession : public Session
{
    FTPSessionInfo* info;
    string response;
    void reset();
    void saveEmail();
    FTPServerConfig* getServerConfig(){return (FTPServerConfig*)conf;}
public:
    FTPSession(TcpSocket* slave,ServerConfig* conf);
    ~FTPSession();
    const string& getResponse() const {return response;}
    void doUser(char* cmd_argv[], int cmd_argc);
    void doPass(char* cmd_argv[], int cmd_argc);
/*    void doPasv(char* cmd_argv[], int cmd_argc);
    void doList(char* cmd_argv[], int cmd_argc);
    void doStor(char* cmd_argv[], int cmd_argc);
    void doDele(char* cmd_argv[], int cmd_argc);
    void doMkd(char* cmd_argv[], int cmd_argc);
    void doCwd(char* cmd_argv[], int cmd_argc);*/
    void doQuit(char* cmd_argv[], int cmd_argc);
    void doUnknown(char* cmd_argv[], int cmd_argc);
    // void setCurrCmd(const char* cmdName);
};



#endif // FTPSESSION_H_INCLUDED
