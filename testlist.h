#ifndef TESTLIST_H
#define TESTLIST_H

#include <QObject>
#include <QWidget>

class TestList : public QObject
{
    Q_OBJECT
    public:
        explicit TestList(QObject *parent = 0);

    private slots: // должны быть приватными
//Methods
        void testAppend();
        void testRemoveElement();
        void testEmpty();
        void testFindElement();
//Operators
        void testOperatorRemove();
        void testOperatorAdd();
        void testOperatorUnion();
        void testOperatorIntersection();
        void testOperatorEqual();
        void testOperatorNotEqual();

};

#endif // TESTLIST_H
