#include <iostream>
#include <queue>
#include <list>
using namespace std;
typedef char Item;

class TreeNode {
	public:
		TreeNode ( Item x );
		Item nodeinfo;
		bool visited;
		void LinkTo ( TreeNode & linknode );
		void Dump();
		list < TreeNode * > get_AdjList ();
	private:
		TreeNode(){};
		list < TreeNode * > AdjNodes_list;

};

list < TreeNode * > TreeNode :: get_AdjList () { return this->AdjNodes_list; }

TreeNode::TreeNode(Item x){
	this->nodeinfo = x;
	this->visited = false;
}

void TreeNode::LinkTo(TreeNode &linknode){ this->AdjNodes_list.push_back(&linknode); }

void TreeNode :: Dump()
{
	cout << endl << "NodeInfo = " << nodeinfo << " Visited = ";
     cout << visited << endl << "Adiacenti =";
	list<TreeNode *>::iterator AdjNodes_list_iter = AdjNodes_list.begin();
	for(;AdjNodes_list_iter!=AdjNodes_list.end();AdjNodes_list_iter++)
		cout << " " << (*AdjNodes_list_iter)->nodeinfo;
	cout << endl;
}

void BFS(TreeNode &k)
{
  queue<TreeNode *> q;
  TreeNode *pCurrentNode;
   q.push(&k);
  k.visited = false;
  cout << endl << "VISITA BFS = ";
  while(!q.empty())
  {  // Estrae un nodo dalla coda
	  pCurrentNode = q.front();
	  if(!pCurrentNode->visited) { // Visita il nodo e lo marca come visitato
		  cout << pCurrentNode->nodeinfo << " ";
		  pCurrentNode->visited = true;
                                                   // Recupera tutti i nodi adiacenti a pCurrentNode
		  list<TreeNode *> AdjNodes_list = pCurrentNode->get_AdjList();
		  q.pop(); // Rimuove dalla coda il nodo appena visitato
		  // Aggiunge nella coda i nodi adiacenti del nodo appena visitato
		  list<TreeNode *>::iterator AdjNodes_list_iter = AdjNodes_list.begin();
		  for(;AdjNodes_list_iter!=AdjNodes_list.end();AdjNodes_list_iter++){
			if(!(*AdjNodes_list_iter)->visited)  q.push((*AdjNodes_list_iter));
		  }
	  }
  }
  cout << endl;
}

void DFS(TreeNode &k)
{
	cout << k.nodeinfo;
	k.visited = true;

	list<TreeNode *> AdjNodes_list = k.get_AdjList();
	list<TreeNode *>::iterator AdjNodes_list_iter = AdjNodes_list.begin();
	for(;AdjNodes_list_iter!=AdjNodes_list.end();AdjNodes_list_iter++)
	{
		if(!(*AdjNodes_list_iter)->visited)
			DFS(*((*AdjNodes_list_iter)));
	}

}

int main()
{
	// Nodi del Grafo
	TreeNode node1('A'); TreeNode node2('B');
	TreeNode node3('C'); TreeNode node4('D');
	TreeNode node5('E'); TreeNode node6('F');

	// Costruzione del grafo (lista di adiacenza)
	node1.LinkTo(node2); node1.LinkTo(node5);
	node2.LinkTo(node3); node3.LinkTo(node4);
	node3.LinkTo(node5); node5.LinkTo(node6);

	node1.Dump(); node2.Dump();
	node3.Dump(); node5.Dump();

	//BFS(node1);
	cout << endl << "VISITA DFS = ";
	DFS(node1);
	cout << endl;
	return 0;
}
