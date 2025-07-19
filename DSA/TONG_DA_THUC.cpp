#include <bits/stdc++.h>
using namespace std;

struct Node {
    int hs, sm;
    Node* next;
    Node(int h, int s) : hs(h), sm(s), next(nullptr) {}
};

void append(Node*& head, int hs, int sm) {
    Node* newNode = new Node(hs, sm);
    if (!head || head->sm < sm) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next && cur->next->sm > sm) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

Node* parsePolynomial(string s) {
    Node* head = nullptr;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    stringstream ss(s);
    string term;

    while (getline(ss, term, '+')) {
        int coef, exp;
        size_t pos = term.find("*x^");
        coef = stoi(term.substr(0, pos));
        exp = stoi(term.substr(pos + 3));
        append(head, coef, exp);
    }

    return head;
}

Node* addPoly(Node* a, Node* b) {
    Node* result = nullptr;
    while (a && b) {
        if (a->sm > b->sm) {
            append(result, a->hs, a->sm);
            a = a->next;
        } else if (a->sm < b->sm) {
            append(result, b->hs, b->sm);
            b = b->next;
        } else {
            int sum = a->hs + b->hs;
            if (sum != 0) append(result, sum, a->sm);
            a = a->next;
            b = b->next;
        }
    }
    while (a) { append(result, a->hs, a->sm); a = a->next; }
    while (b) { append(result, b->hs, b->sm); b = b->next; }
    return result;
}

void printPoly(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->hs << "*x^" << cur->sm;
        if (cur->next) cout << " + ";
        cur = cur->next;
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        Node* poly1 = parsePolynomial(s1);
        Node* poly2 = parsePolynomial(s2);
        Node* result = addPoly(poly1, poly2);
        printPoly(result);
    }
    return 0;
}
