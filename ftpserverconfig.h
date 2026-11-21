#ifndef FTPACCOUNT_H_
#define FTPACCOUNT_H_
#include <filesystem>
#include "serverconfig.h"
namespace fs = std::filesystem;
class FTPAccount: public Account
{
protected:
    bool read;
    bool write;
public:
    FTPAccount();
    FTPAccount(string username);
    ~FTPAccount();
    string getUsername() const;
    bool Readable() const
    {
        return this->read;
    }
    bool Writeable() const
    {
        return this->write;
    }
    void setRead(bool read)
    {
        this->read = read;
    }
    void setWrite(bool write)
    {
        this->write = write;
    }
};

class FTPServerConfig: public ServerConfig
{
private:
    unsigned short connTimeout = 0;
    fs::path rootDir;
public:
    FTPServerConfig();
    ~FTPServerConfig();
    void setConnTimeout(unsigned short timeout);
    void setRootDir(const string& dir);
    const fs::path& getRootDir(){
        return this->rootDir;
    }
    
    void loadAccountsFromFile(const string& fileName);
    void loadServerConfig(const string& confFileName);
    bool isValidAccount(const string& accountName);
};


#endif // FTPACCOUNT_H_
