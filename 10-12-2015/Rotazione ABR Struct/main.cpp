#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef int Item;

struct node
{
  Item item;
  node *l;
  node *r;
};

typedef  node *link;

void VisitaNodo(link h){
	cout << "Nodo visitato = " << h->item << endl;
}

void traverse(link h, void visit(link)){
  if (h == 0) return;
  visit(h);
  traverse(h->l, visit);
  traverse(h->r, visit);
}

int count(link h){
  if (h == 0) return 0;
  return count(h->l) + count(h->r) +1;
}

int height(link h){
 if ( h == 0) return -1;
 int u =0,v=0;
 if (h->l != NULL)
	 u= height(h ->l);
 if (h->r != NULL)
	 v= height(h ->r);
 if (u > v) return u+1;
  else return v+1;
}

void printnode(Item x, int h) {
  for (int i=0; i < h; i++)  cout << " ";
  if (x == '*')
	  cout << "*" << endl;
  else
	cout << x << endl;
}

void show(link t, int h) {
 if ( t == NULL)
 {
	 printnode('*', h);
	 return;
 }
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

void rotR(link &h)
{
  link x= h->l;
  h->l = x->r;
  x->r = h;
  h = x;
}

void  rotL(link &h)
{
 link x = h->r;
 h->r = x->l;
 x->l = h;
 h=x;
}

void insertT(link &h, Item x){
	if (h == NULL) {
		h = new node;
		h->item = x;
		h->l = h->r = NULL;
		return;
	}
      if (x < h->item) {
		insertT(h->l, x);
		rotR(h);
	}
	else {
		insertT(h->r, x);
        rotL(h);
	}
}

int main() {

	link root=NULL, node_3=NULL, node_9=NULL, node_11=NULL, node_15=NULL, node_7=NULL, node_12=NULL;

	root = new node; node_3 = new node; node_9 = new node; node_11 = new node;
	node_15 = new node; node_7 = new node; node_12 = new node;

	build(node_3, NULL, NULL, 3); build(node_9, NULL, NULL, 9);
	build(node_11, NULL, NULL, 11); build(node_15, NULL, NULL, 15);
	build(node_7, node_3, node_9, 7); build(node_12, node_11, node_15, 12);
	build(root, node_7, node_12, 10);

	show(root, height(root));
	cout << "Height = " << height(root) << endl;
	cout << "Count = " << count(root) << endl;
	traverse(root, VisitaNodo);
	insertT(root, 1);
	show(root, height(root));

	return 0;
}
