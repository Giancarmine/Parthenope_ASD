#include <iostream>
#include <string>

using namespace std;

struct node
{
    char item;
    node *l;
    node *r;
};

typedef  node *link;

void pippo(link h){
    cout << "Nodo visitato = " << h->item << endl;
}

void traverse(link h, void visit(link))
{
    if (h == 0) return;
    visit(h);
    traverse(h->l, visit);
    traverse(h->r, visit);
}

int count(link h)
{
    if (h == 0) return 0;
    return count(h ->l) + count(h->r) +1;
}
int height(link h)
{
    if ( h == 0) return -1;
    int u= height(h ->l), v= height(h ->r);
    if ( u > v) return u+1;
    else return v+1;
}

void printnode(Item x, int h)
{
    for (int i=0; i < h; i++)  cout << " ";
    cout << x << endl;
}
void show(link t, int h)
{
    if ( t == NULL) { printnode('*', h); return;}
    show(t ->r, h+1);
    printnode(t->item, h);
    show(t->l, h+1);
}
void build(link t, link l, link r, Item x)
{
	t->l = l;
	t->r = r;
	t->item = x;
}

int main() {

    link root=NULL, B=NULL, C=NULL, D=NULL, E=NULL;
    link F=NULL, G=NULL;
    root = new node;
    B = new node; C = new node; D = new node; E = new node;
    F = new node; G = new node;

    build(F, NULL, NULL, 'F'); build(G, NULL, NULL, 'G');
    build(C, NULL, NULL, 'C'); build(E, NULL, NULL, 'E');
    build(B, F, G, 'B'); build(D, C, E, 'D'); build(root, B, D, 'R');

    show(root, height(root));
    cout << "Height = " << height(root) << endl;
    cout << "Count = " << count(root) << endl;
    traverse(root, pippo);

    return 0;
}

