#include "Ceasercipher.h"
#include "Messagepopup.h"
#include<QTextStream>
CeaserCipher::CeaserCipher()
{

}

bool CeaserCipher::validateFile(QString &filePath)
{
    currFilePath = filePath;
    //fileEnc = new QFile();
    //fileEnc->link(currFilePath);
    QFile inputFile(filePath);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          fileStorage.push_back(line.toStdString());
       }
       inputFile.close();
        return true;
    }else{
        messageDialog = "File Doesn't Exist";
        popUpSetMessage(messageDialog);
    }
}

std::vector<std::string> CeaserCipher::storeFileData()
{
    std::vector<std::string>tmp;
   // while(!fileEnc.eof()){
   //     std::getline(fileEnc,buffer);
   //     tmp.push_back(buffer);
   //     buffer.clear();
   // }
    return tmp;
}

bool CeaserCipher::encryptFile()
{
    if(fileStorage.front() == "E"){
        messageDialog = "File is already Encrypted";
        popUpSetMessage(messageDialog);
        return false;
    }else{
        fileStorage.front() = "E";
        for(auto i : fileStorage){
            if(i != "E"){
                i = encryptionAlgorithm(i,8);
            }
        }
        writeToFile();
        messageDialog = "File Has Been Encrypted";
        popUpSetMessage(messageDialog);
        return true;
    }
}

bool CeaserCipher::decryptFile()
{
    if(fileStorage.front() == "D"){
        messageDialog = "File is already Decrypted";
        popUpSetMessage(messageDialog);
        return false;
    }else{
        fileStorage.front() = "D";
        for(auto i : fileStorage){
            if(i !="D"){
                i= decryptionAlgorithm(i,8);
            }
        }
        writeToFile();

        messageDialog = "File Has Been Decrypted";
        popUpSetMessage(messageDialog);
        return true;
    }
}

void CeaserCipher::writeToFile()
{
   QFile outFile(currFilePath);
   outFile.resize(0);
   if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
           return;

   QTextStream out(&outFile);
   for(auto i : fileStorage){
       out <<QString::fromStdString(i) << "\n";
   }
}

void CeaserCipher::popUpSetMessage(QString &s)
{
    MessagePopup *mess = new MessagePopup;
    mess->setMessage(s);
    mess->show();

}

std::string CeaserCipher::encryptionAlgorithm(std::string &s, int k)
{
    const int START_BETA = 96;
    const int START_ALPHA = 64;
    const int ALPHA = 90;
    const int BETA = 122;
    std::for_each(s.begin(), s.end(),
        [
            k, START_BETA, START_ALPHA, ALPHA, BETA
        ]
    (char& c)
        {
            if (!ispunct(c) && !isspace(c) && !isdigit(c)) {
                if (islower(c)) {
                    if (c + k <= BETA)c += k;
                    else {
                        for (int i = 0; i < k; i++) {
                            c += 1;
                            if (c > BETA) {
                                c = START_BETA + 1;
                            }
                        }
                    }
                }
                if (isupper(c)) {
                    if (c + k <= ALPHA)c += k;
                    else {
                        for (int i = 0; i < k; i++) {
                            c += 1;
                            if (c > ALPHA) {
                                c = START_ALPHA + 1;
                            }
                        }
                    }
                }

            }
        });
    return s;
}

std::string CeaserCipher::decryptionAlgorithm(std::string &s, int k)
{
    const int START_BETA = 122;
        const int START_ALPHA = 90;
        const int ALPHA = 65;
        const int BETA = 97;
        std::for_each(s.begin(), s.end(),
            [
                k, START_BETA, START_ALPHA, ALPHA, BETA
            ]
        (char& c)
            {
                if (!ispunct(c) && !isspace(c) && !isdigit(c)) {
                    if (islower(c)) {
                        if (std::abs(c - k) >= BETA)std::abs(c = c - k);
                        else {
                            for (int i = 0; i < k; i++) {
                                c -= 1;
                                if (c < BETA) {
                                    c = START_BETA;
                                }
                            }
                        }
                    }
                    if (isupper(c)) {
                        if (std::abs(c - k) >= ALPHA)std::abs(c = c - k);
                        else {
                            for (int i = 0; i < k; i++) {
                                c -= 1;
                                if (c < ALPHA) {
                                    c = START_ALPHA;
                                }
                            }
                        }
                    }

                }
            });
        return s;
}


