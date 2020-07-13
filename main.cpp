#include <QApplication>
#include <QTest>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <testlist.h>
#include <list.h>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <algorithm>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
//    List<int> b;
//    List<int> c;
//    c.append(8);
//    b.append(8);
//    cout << (c == b) << endl;
//    cout << (c != b) << endl;
//    //cin >> b;
//    cout << b << endl;
//    c |= 13;
//    c |= 112;
//    c |= 121;
//    c |= 10;
//    c /= 10;
//    cout << c << endl;
//    cout << "-1-" << b << "--" <<endl;
//    b.remove();
//    cout << "-2-" << b << "--" << endl;
//    b.append(8);
//    cout << "-3-" << b << "--" << endl;
//    b.append(12);
//    b.append(121);
//    b.append(11);
//    b.append(13);
//    cout << "-4-" << b << "--" << endl;
//    //cout << b.searchElement(121).getData() << endl;
//    b.removeElement(-12);
//    cout << "-b = -" << b << "--" << endl;
//    cout << "-c = -" << c << "--" << endl;
//    //List<int> d = (c.intersection(b));
//    //List<int> t = (c && b);
//    cout << endl << typeid(b).name() << endl;
//    cout << endl << typeid(c).name() << endl;
//    cout << endl << typeid(b && c).name() << endl;
//    List<int> t = (c && b);
//    cout << t << endl;
//    //List<int> e = b.newUnion(c);
    //cout << e << endl;

    setlocale(LC_ALL, "Russian");
    QFile temp("C://Users/Dany/Desktop/shep_zhit_sp_iw_1-master/Text_1.txt");
    QFile temp1("C://Users/Dany/Desktop/shep_zhit_sp_iw_1-master/Text_New.txt");
        if (temp.open(QIODevice::ReadOnly) && temp1.open(QIODevice::WriteOnly)) {
            QTextStream out(&temp1);
            while (!temp.atEnd()) {
                QString line = temp.readLine();
                line = line.toLower();
                //cout << line << endl;
                QStringList list = line.split(" ");
                list = list.replaceInStrings(",", "");
                list = list.replaceInStrings(".", "");
                //cout << list <<endl;
                for (int i = 0; i < list.size(); i++){
                out << list[i];
                if(i < list.size()-1) out << " ";
                }
                //out << Qt::endl;
            }
        }
        temp.close();
        temp1.close();
        QFile temp2("C://Users/Dany/Desktop/shep_zhit_sp_iw_1-master/Text_2.txt");
        QFile temp3("C://Users/Dany/Desktop/shep_zhit_sp_iw_1-master/Text_New_2.txt");
            if (temp2.open(QIODevice::ReadOnly) && temp3.open(QIODevice::WriteOnly)) {
                QTextStream out(&temp3);
                while (!temp2.atEnd()) {
                    QString line = temp2.readLine();
                    line = line.toLower();
                    //cout << line << endl;
                    QStringList list = line.split(" ");
                    list = list.replaceInStrings(",", "");
                    list = list.replaceInStrings(".", "");
                    //cout << list <<endl;
                    for (int i = 0; i < list.size(); i++){
                    out << list[i];
                    if(i < list.size()-1) out << " ";
                    }
                    //out << Qt::endl;
                }
            }
            temp2.close();
            temp3.close();
    //temp
    //QFile res1("C://Users/Dany/Desktop/shep_zhit_sp_iw_1-master/Text_New.txt");
    //QFile res2("C://Users/Dany/Desktop/shep_zhit_sp_iw_1-master/Text_New_2.txt");
            QString t;
            List<string> Result;
    if (temp1.open(QIODevice::ReadOnly) && temp3.open(QIODevice::ReadOnly)) {
        while (!temp1.atEnd()) {
            QString line = temp1.readLine();
            QStringList list = line.split(" ");
            for (int i = 0; i < list.size(); i++){
            t = (list[i]).replace(" ","");
            t = t.replace("\r","");
            t = t.replace("\n","");
            if(t != "") {Result.append(qPrintable(t));}
            }
            //out << Qt::endl;
        }
        while (!temp3.atEnd()) {
            QString line = temp3.readLine();
            QStringList list = line.split(" ");
            for (int i = 0; i < list.size(); i++){
                t = (list[i]).replace(" ","");
                t = t.replace("\r","");
                t = t.replace("\n","");
            if(t != "") {Result.append(qPrintable(t));}
            //cout << list[i] << endl;
            }
            //out << Qt::endl;
        }
    }
    QTextStream outNew(stdout);
    //out << qstr;
    cout << Result;

    freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QTest::qExec(new TestList, argc, argv);
    return 0;
}
