#include <iostream>
#include <string>
#define FOR ME
#define int unsigned long long int
using namespace std;
struct Node
{
    int piece;
    Node* next;
};


Node* Head_a = nullptr, * Head_b = nullptr, * Head_c = nullptr;


Node* CreateNode(int piece)
{
    Node* NewNode = new Node;
    NewNode->piece = piece;
    NewNode->next = nullptr;
    return NewNode;
}


void AddFirst(Node* NewNode, Node*&Head) 
{
    if (!Head)
    {
        Head = NewNode;
        return;
    }
    else
    {
        NewNode->next = Head;
        Head = NewNode;
    }
}


void Delete_q(Node* q, Node*&Head)
{
    Node* p = Head;
    if (!p->next) {
        delete p;
        Head = nullptr;
        return;
    }
    while (p->next != q) {
        p = p->next;
        if (!p) {
            return;
        }
    }
    delete q;
    q = nullptr;
    if (p) p->next = nullptr;
}

void print(Node* Head);


void razbiv_plus(string &a, string &b) 
{
    string a_piece, b_piece;
    int c_length;
    (a.length() >= b.length()) ? c_length = a.length() : c_length = b.length();
    while (a.length() > 9) {
        a_piece.assign(a, a.length() - 9, 9);
        a.erase(a.length() - 9, 9);
        //int a_piece_int = stoi(a_piece);
        int a_piece_int = strtoul(a_piece.c_str(), nullptr, 10);
        Node* NewNode_a = CreateNode(a_piece_int);
        AddFirst(NewNode_a, Head_a);
    }
    int a_piece_int = strtoul(a.c_str(), nullptr, 10);
    Node* NewNode_a = CreateNode(a_piece_int);
    AddFirst(NewNode_a, Head_a);
    while (b.length() > 9) {
        b_piece.assign(b, b.length() - 9, 9);
        b.erase(b.length() - 9, 9);
        //int b_piece_int = stoi(b_piece);
        int b_piece_int = strtoul(b_piece.c_str(), nullptr, 10);
        CreateNode(b_piece_int);
        Node* NewNode_b = CreateNode(b_piece_int);
        AddFirst(NewNode_b, Head_b);
    }
    int b_piece_int = strtoul(b.c_str(), nullptr, 10);
    Node* NewNode_b = CreateNode(b_piece_int);
    AddFirst(NewNode_b, Head_b);

#ifdef FOR ME
    cout << endl << "=======================================================" << endl;
    print(Head_a);
    cout << endl << "=======================================================" << endl;
    print(Head_b);
    cout << endl << "=======================================================" << endl;
#endif

    while(c_length>0)
    {
        Node* q_a = Head_a;
        Node* q_b = Head_b;
        if (Head_a) {
            while (q_a->next) {
                q_a = q_a->next;
            }
        }
        if (Head_b) {
            while (q_b->next) {
                q_b = q_b->next;
            }
        }
        Node* NewNode = CreateNode(0);
        if (q_a && q_b)
        {
            NewNode->piece = q_a->piece + q_b->piece;
            Delete_q(q_a, Head_a);
            Delete_q(q_b, Head_b);
        }
        else if (q_a && !q_b)
        {
            NewNode->piece = q_a->piece;
            Delete_q(q_a, Head_a);
        }
        else if (!q_a && q_b)
        {
            NewNode->piece = q_b->piece;
            Delete_q(q_b, Head_b);
        }
        else break;
        AddFirst(NewNode, Head_c);
        c_length -= 9;
    }
}


void print(Node* Head)
{
    Node* q = Head;
    while (q)
    {
        cout << q->piece;
        q = q->next;
    }
}

void main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите два числа, которые хотите сложить:" << endl;
    string a, b;
    cin >> a;
    cin >> b;
    razbiv_plus(a, b);
    print(Head_c);
}

