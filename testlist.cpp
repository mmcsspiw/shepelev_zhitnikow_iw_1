#include "testlist.h"
#include <QTest>
#include "list.h"

TestList::TestList(QObject *parent) :
    QObject(parent)
{

}
//Methods
void TestList::testAppend()
{
    List<int> Test;
    Test.append(8);
    Test.append(8);
    Test.append(8);
    QCOMPARE(8, Test.getElementByIndex(0));
    Test.append(9);
    QCOMPARE(8, Test.getElementByIndex(1));
    QCOMPARE(9, Test.getElementByIndex(0));
    Test.remove();
}
void TestList::testRemoveElement(){
    List<int> Test;
    Test.append(8);
    QCOMPARE(8, Test.getElementByIndex(0));
    Test.removeElement(8);
    Test.append(9);
    QCOMPARE(9, Test.getElementByIndex(0));
    Test.remove();
};
void TestList::testEmpty(){
    List<int> Test;
    Test.append(8);
    QCOMPARE(false, Test.isEmpty());
    Test.remove();
    QCOMPARE(true, Test.isEmpty());
};
void TestList::testFindElement(){
    List<int> Test;
    Test.append(8);
    QCOMPARE(8, Test.getElementByIndex(0));
    Test.append(9);
    QCOMPARE(9, Test.getElementByIndex(0));
    Test.append(10);
    QCOMPARE(10, Test.getElementByIndex(0));
    QCOMPARE(9, Test.getElementByIndex(1));
    QCOMPARE(8, Test.getElementByIndex(2));
    Test.remove();
};
//Operators

void TestList::testOperatorRemove(){
    List<int> Test;
    Test |= 12;
    Test |= 13;
    Test |= 10;
    Test |= 8;
    Test /= 8;
    QCOMPARE(10, Test.getElementByIndex(0));
    Test /= 12;
    //cout << Test.getElementByIndex(0) <<endl;
    QCOMPARE(10, Test.getElementByIndex(0));
    Test.remove();
};
void TestList::testOperatorAdd(){
    List<int> Test;
    Test |= 8;
    QCOMPARE(8, Test.getElementByIndex(0));
    Test |= 10;
    QCOMPARE(10, Test.getElementByIndex(0));
    Test.remove();
};
void TestList::testOperatorUnion(){
    List<int> Test;
    List<int> Test1;
    List<int> res;
    List<int> res1;
    res1.append(8);
    res1.append(10);
    res1.append(12);
    Test.append(8);
    Test.append(10);
    Test1.append(12);
    Test1.append(10);
    res = Test || Test1;
    QCOMPARE(true, res == res1);
    Test.remove();
    Test1.remove();
    res.remove();
    res1.remove();
};
void TestList::testOperatorIntersection(){
    List<int> Test;
    List<int> Test1;
    List<int> res;
    List<int> res1;
    res1.append(10);
    Test.append(8);
    Test.append(10);
    Test1.append(12);
    Test1.append(10);
    res = Test && Test1;
    QCOMPARE(true, res == res1);
    Test.remove();
    Test1.remove();
    res.remove();
    res1.remove();
};
void TestList::testOperatorEqual(){
    List<int> Test;
    List<int> Test1;
    Test.append(8);
    Test1.append(8);
    QCOMPARE(true, Test==Test1);
    Test1.append(19);
    QCOMPARE(false, Test==Test1);
    Test.remove();
    Test1.remove();
};
void TestList::testOperatorNotEqual(){
    List<int> Test;
    List<int> Test1;
    Test.append(8);
    Test1.append(8);
    QCOMPARE(false, Test!=Test1);
    Test1.append(19);
    QCOMPARE(true, Test!=Test1);
    Test.remove();
    Test1.remove();
};
