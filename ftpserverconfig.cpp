#include <fstream>
#include <iostream>
#include <cstring>
#include "ftpserverconfig.h"
using namespace std;

FTPAccount::FTPAccount()
{
}
FTPAccount::FTPAccount(string username):Account(username)
{

}

FTPAccount::~FTPAccount()
{
}

string FTPAccount::getUsername() const
{
    return this->username;
}


FTPServerConfig::FTPServerConfig()
{
}

FTPServerConfig::~FTPServerConfig()
{
}


bool FTPServerConfig::isValidAccount(const string& accountName)
{
    return isValidUser(accountName);
}

void FTPServerConfig::setConnTimeout(unsigned short timeout)
{
    connTimeout = timeout;
}
void FTPServerConfig::setRootDir(const string& dir)
{
    rootDir = dir;
}

void FTPServerConfig::loadServerConfig(const string& confFileName)
{

}

void FTPServerConfig::loadAccountsFromFile(const string& fileName)
{
    ifstream f(fileName,ios::in);
    if(!f.good())
    {
        throw ServerConfigException("can not open FTP account list file\n");
    }
    else
    {
        char str[128];
        while(!f.eof())
        {
            f.getline(str,128);
            if(strlen(str)>0)
            {
                FTPAccount* acc = new FTPAccount();
                acc->setUserName(str);
                // Đọc mật khẩu và quyền truy cập từ file cấu hình
                char* token = strtok(str, ",");
                if (token != nullptr) {
                    acc->setUserName(token);
                    token = strtok(nullptr, ",");
                    if (token != nullptr) {
                        acc->setPassword(token);
                        token = strtok(nullptr, ",");
                        if (token != nullptr) {
                            acc->setRead(strcmp(token, "true") == 0);
                            token = strtok(nullptr, ",");
                            if (token != nullptr) {
                                acc->setWrite(strcmp(token, "true") == 0);
                            }
                        }
                    }
                }
                addAccount(acc);
            }
        }
        cout << "FTP Server accounts loaded from file: " << fileName << endl;
        f.close();
    }
}
