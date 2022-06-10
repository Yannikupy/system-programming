//                 lexer.h 2021
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
class tLexer:public tBaseLexer{
public:
//�����������
 tLexer():tBaseLexer(){
//������� ��������:

//�����
    addstr(Aint, 0, "-+", 1);
    addrange(Aint, 0 , '0', '9', 2);
    addrange(Aint, 1 , '0', '9', 2);
    addrange(Aint, 2 , '0', '9', 2);
    Aint.final(2);
// ������������
    addstr(Adec,0,"-+",1);
    addrange(Adec,1,'0','9',2);
    addstr(Adec,1,".",3);
    addrange(Adec,2,'0','9',2);
    addstr(Adec,2,".",3);
    addrange(Adec,3,'0','9',4);
    addrange(Adec,4,'0','9',4);
    addstr(Adec,4,"eE",5);
    addstr(Adec,5,"-+",6);
    addrange(Adec,5,'0','9',7);
    addrange(Adec,6,'0','9',7);
    addrange(Adec,7,'0','9',7);
    Adec.final(7);
//________________________________________

// �������������
    addstr(Aid,0,"!",   1);
    addrange(Aid,0, 'a', 'z', 1);
    addrange(Aid,0, 'A', 'Z', 1);
    addstr(Aid,1,"!",   1);
    addrange(Aid,1, 'a', 'z', 1);
    addrange(Aid,1, 'A', 'Z', 1);
    addrange(Aid,1, '0', '9', 1);
    addstr(Aid,1,"-",   3);
    addstr(Aid,3,"!-",   1);
    addrange(Aid,3, 'a', 'z', 1);
    addrange(Aid,3, 'A', 'Z', 1);
    addrange(Aid,3, '0', '9', 1);
    addstr(Aid,2,"!-",   1);
    addrange(Aid,2, 'a', 'z', 1);
    addrange(Aid,2, 'A', 'Z', 1);
    addrange(Aid,2, '0', '9', 1);
    addstr(Aid, 0, "?", 2);
    addstr(Aid, 1, "?", 2);
    addstr(Aid, 2, "?", 2);
    Aid.final(1);
//________________________________________

// ������������� ���������
    addstr(Aidq,0,"!",   1);
    addrange(Aidq, 0, 'a', 'z', 1);
    addrange(Aidq, 0, 'A', 'Z', 1);
    addstr(Aidq,0,"?",   2);
    addstr(Aidq, 1, "!", 1);
    addrange(Aidq, 1, 'a', 'z', 1);
    addrange(Aidq, 1, 'A', 'Z', 1);
    addrange(Aidq, 1, '0', '9', 1);
    addstr(Aidq, 2, "!", 1);
    addrange(Aidq, 2, 'a', 'z', 1);
    addrange(Aidq, 2, 'A', 'Z', 1);
    addrange(Aidq, 2, '0', '9', 1);
    addstr(Aidq, 3, "!", 1);
    addrange(Aidq, 3, 'a', 'z', 1);
    addrange(Aidq, 3, 'A', 'Z', 1);
    addrange(Aidq, 3, '0', '9', 1);
    addstr(Aidq,1,"?",   2);
    addstr(Aidq,2,"?",   2);
    addstr(Aidq, 0, "-", 4);
    addstr(Aidq, 3, "-", 4);
    addstr(Aidq, 1, "-", 4);
    addstr(Aidq, 2, "-", 4);
    addstr(Aidq, 4, "-", 1);
    addstr(Aidq, 4, "?", 2);
    addstr(Aidq, 4, "!", 3);
    addrange(Aidq, 4, 'a', 'z', 1);
    addrange(Aidq, 4, 'A', 'Z', 1);
    addrange(Aidq, 4, '0', '9', 1);
    Aidq.final(2);
}
};
#endif

