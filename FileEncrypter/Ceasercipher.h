#ifndef CEASERCIPHER_H
#define CEASERCIPHER_H
#include<vector>
#include<fstream>
#include<algorithm>
#include<QString>
#include<QFile>
class CeaserCipher
{
public:
    CeaserCipher();
    bool validateFile(QString &filePath);
    std::vector<std::string> storeFileData();
    bool encryptFile();
    bool decryptFile();
    std::string encryptionAlgorithm(std::string &s,int k);
    std::string decryptionAlgorithm(std::string &s,int k);
    void writeToFile();
    void popUpSetMessage(QString &s);
    std::vector<std::string>fileStorage;
private:
    QFile* fileEnc;
    QString currFilePath;
    std::ofstream writeToFileStream;
    std::string buffer;

    QString messageDialog;
};

#endif // CEASERCIPHER_H
