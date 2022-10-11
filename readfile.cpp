#include "readfile.h"
#include "sortArray.h"
readFile::readFile(QObject *parent) : QObject(parent)
{
    read();
    rowSort = twoArray.size();
    colorString();
    //readColor();
    //    qDebug() << getData(0,1);
    //qDebug() << getRow() << " " << getColumn();
    //    filterString("Gia",2);
    //    filterStringGroup("6", "","","");
}

QString readFile::read()
{
    twoArray.clear();
    QFile file(sourceFile);
    //    QString fileConent;
    if (file.open(QIODevice::ReadOnly)) {
        QString line;
        QTextStream t(&file);
        do {
            line = t.readLine();
            QStringList word = line.split("; ");
            if (word.value(0) != "")
            {
                QVector<QString> a;
                for (int j = 0; j < word.size(); j++)
                {
                    a.push_back(word.value(j));
                }
                twoArray.push_back(a);
            }
        }
        while(!line.isNull());

        //        for (int i = 0; i < twoArray.size(); i++)
        //        {
        //            for (int j = 0; j < twoArray[i].size() ; j++)
        //            {
        //                qDebug() << twoArray[i][j] << " ";
        //            }
        //            //            qDebug() << "\n";
        //        }
        //        for (int j = 0; j < twoArray.size() ; j++)
        //        {
        //            qDebug() << twoArray[j][3].toLongLong();
        //        }
        file.close();
        //qDebug() << twoArray[1][0];
    }
    else {
        qDebug() << "Unable to open the file";
        return QString();
    }
    //    quickSort(twoArray,0,14);
    //    qDebug() << "?: " + twoArray[0][0];
    return "";
}

QString readFile::getData(int x, int y)
{
    return twoArray[x][y];
}

int readFile::getColumn()
{
    //read();
    return twoArray[1].size();
}

int readFile::getRow()
{
    //read();
    return rowSort;
}
void readFile::readColor()
{
    //    QFile file("D:/anhthong/DS_training/trainDs/trainDS/file/config.json");
    QFile file("D:/anhthong/DS_training/11_10/train-dev/file/config.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if(doc.isNull()) {
        qDebug() << "Parse failed";
    }
    QJsonObject rootObject = doc.object();
    //qDebug() << rootObject.value("level1").toString();
    for (int i = 0; i <= 4; i++)
    {
        colorConfig.push_back(rootObject.value("level" + QString::number(i+1)).toString());
        qDebug() << colorConfig[i];
    }
}

QString readFile::getColor(int index)
{
    return colorConfig[index];
}

void readFile::sapXep(int id)
{
    switch(id)
    {
    /*sort by ID*/
    case 1:
        quickSort(twoArray,0,rowSort - 1 ,1,0);
        colorString();
        break;
    case 2:
        quickSort(twoArray,0,rowSort - 1,2,0);
        colorString();
        break;
        /*sort by Level*/
    case 3:
        quickSort(twoArray, 0,rowSort - 1,1,3);
        colorString();
        break;
    case 4:
        quickSort(twoArray, 0,rowSort - 1,2,3);
        colorString();
        break;
        /*sort by Name*/
    case 5:
        quickSortString(twoArray, 0, rowSort - 1, 1, 1);
        colorString();
        break;
    case 6:
        quickSortString(twoArray, 0, rowSort - 1, 2, 1);
        colorString();
        break;
        /*sort by Country*/
    case 7:
        quickSortString(twoArray, 0, rowSort - 1, 1,2);
        colorString();
        break;
    case 8:
        quickSortString(twoArray,0,rowSort -1, 2, 2);
        colorString();
        break;
    }
}

void readFile::filterID(int header)
{
    twoArray.clear();
    QFile file(sourceFile);
    //    QString fileConent;
    if (file.open(QIODevice::ReadOnly)) {
        if (header != 0)
        {
            QString line;
            QTextStream t(&file);
            do {
                line = t.readLine();
                QStringList word = line.split("; ");
                if (word.value(0) != "")
                {
                    QVector<QString> a;

                    for (int j = 0; j < word.size(); j++)
                    {
                        if (word.value(3) == QString::number(header))
                        {
                            a.push_back(word.value(j));
                        }
                        else {
                            a.push_back("");
                        }
                    }
                    twoArray.push_back(a);
                }
            }

            while(!line.isNull());
        }
        else {
            twoArray.clear();
            QFile file(sourceFile);
            //    QString fileConent;
            if (file.open(QIODevice::ReadOnly)) {
                QString line;
                QTextStream t(&file);
                do {
                    line = t.readLine();
                    QStringList word = line.split("; ");
                    if (word.value(0) != "")
                    {
                        QVector<QString> a;
                        for (int j = 0; j < word.size(); j++)
                        {
                            a.push_back(word.value(j));
                        }
                        twoArray.push_back(a);
                    }
                }
                while(!line.isNull());
            }
            file.close();
        }
        sapXep(4);
    }
}

void readFile::filterString(QString str, int header)
{
    if (str != "")
    {
        twoArray.clear();
        QFile file(sourceFile);
        //    QString fileConent;
        if (file.open(QIODevice::ReadOnly)) {
            QString line;
            QTextStream t(&file);
            do {
                line = t.readLine();
                QStringList word = line.split("; ");
                if (word.value(0) != "")
                {
                    QVector<QString> a;
                    int b = 0;
                    for (int i = 0; i < str.length(); i++)
                    {
                        if (word.value(header)[i].toLower() == str[i].toLower())
                        {
                            b++;
                        }
                    }
                    for (int j = 0; j < word.size(); j++)
                    {
                        if (b == str.length())
                        {
                            a.push_back(word.value(j));
                        }
                        else {
                            a.push_back("");
                        }
                    }
                    twoArray.push_back(a);
                }
            }
            while(!line.isNull());
            for (int i = 0; i < twoArray.size(); i++)
            {
                for (int j = 0; j < twoArray[i].size() ; j++)
                {
                    qDebug() << twoArray[i][j] << " ";
                }
            }
            file.close();
        }
        sapXep(4);
    }
    else {
        twoArray.clear();
        QFile file(sourceFile);
        //    QString fileConent;
        if (file.open(QIODevice::ReadOnly)) {
            QString line;
            QTextStream t(&file);
            do {
                line = t.readLine();
                QStringList word = line.split("; ");
                if (word.value(0) != "")
                {
                    QVector<QString> a;
                    for (int j = 0; j < word.size(); j++)
                    {
                        a.push_back(word.value(j));
                    }
                    twoArray.push_back(a);
                }
            }
            while(!line.isNull());
        }
        file.close();
    }
}

void readFile::filterStringGroup(QString str1, QString str2, QString str3, QString str4)
{
    if (str4 == "0" && str2 == "" && str3 == "" && str1 == "") {
        qDebug() << "ok";
        twoArray.clear();
        QFile file(sourceFile);
        //    QString fileConent;
        if (file.open(QIODevice::ReadOnly)) {
            QString line;
            QTextStream t(&file);
            do {
                line = t.readLine();
                QStringList word = line.split("; ");
                if (word.value(0) != "")
                {
                    QVector<QString> a;
                    for (int j = 0; j < word.size(); j++)
                    {
                        a.push_back(word.value(j));
                    }
                    twoArray.push_back(a);
                }
            }
            while(!line.isNull());
        }
        colorString();
        rowSort = twoArray.size();
        file.close();
    }
    else {
        twoArray.clear();
        QFile file(sourceFile);
        //    QString fileConent;
        if (file.open(QIODevice::ReadOnly)) {
            QString line;
            QTextStream t(&file);
            do {
                line = t.readLine();
                QStringList word = line.split("; ");
                if (word.value(0) != "")
                {
                    QVector<QString> a;
                    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
                    //                if (str4 != "") {
                    for (int i = 0; i < str1.length(); i++)
                    {
                        if (word.value(0)[i].toLower() == str1[i].toLower())
                        {
                            num1++;
                        }
                    }
                    for (int i = 0; i < str2.length(); i++)
                    {
                        if (word.value(1)[i].toLower() == str2[i].toLower())
                        {
                            num2++;
                        }
                    }
                    for (int i = 0; i < str3.length(); i++)
                    {
                        if (word.value(2)[i].toLower() == str3[i].toLower())
                        {
                            num3++;
                        }
                    }
                    if (str4 != "0")
                    {
                        for (int i = 0; i < str4.length(); i++)
                        {
                            if (word.value(3)[i] == str4[i])
                            {
                                num4++;
                            }
                        }

                        for (int j = 0; j < word.size(); j++)
                        {
                            if (num1 == str1.length() && num2 == str2.length() && num3 == str3.length() && num4 == str4.length())
                            {
                                a.push_back(word.value(j));
                            }
                            else {
                                a.push_back("");
                            }
                        }
                        twoArray.push_back(a);
                    } else {
                        for (int j = 0; j < word.size(); j++)
                        {
                            if (num1 == str1.length() && num2 == str2.length() && num3 == str3.length())
                            {
                                a.push_back(word.value(j));
                            }
                            else {
                                a.push_back("");
                            }
                        }
                        twoArray.push_back(a);
                    }
                }
            }
            while(!line.isNull());
            //        for (int i = 0; i < twoArray.size(); i++)
            //        {
            //            for (int j = 0; j < twoArray[i].size() ; j++)
            //            {
            //                qDebug() << twoArray[i][j] << " ";
            //            }
            //        }
            file.close();
        }
        rowSort = twoArray.size();
        sapXep(4);
        int count = 0;
        for (int i = 0; i < 15; i++)
        {
            if (twoArray[i][0] != "")
            {
                count ++;
            }
        }

        if (count == 0)
        {
            rowSort = twoArray.size();
        }
        else {
            rowSort = count;
        }

        qDebug() << "rowSort" << rowSort;
    }
}

void readFile::colorString()
{
    color.clear();
    for (int i = 0; i < twoArray.size(); i++)
    {
        for (int  j = 0; j < 4 ; j++)
        {
            color.push_back(twoArray[i][3]);
        }
    }

    for (int i = 0 ; i < color.size(); i++)
    {
        qDebug() << color[i];
    }
}

QString readFile::getColorString(int index)
{
    if (color[index] == "1")
    {
        return "green";
    }
    else if (color[index] == "2")
    {
        return "yellow";
    }
    else if (color[index] == "3")
    {
        return "red";
    }
    else if (color[index] == "4")
    {
        return "blue";
    }
    else
    {
        return "white";
    }

}
