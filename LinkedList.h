
struct nodeL {
	int val;
	nodeL *sled;
};

void ListMenu();
void addBegin(nodeL **, nodeL **);
void addLast(nodeL **);
void print(nodeL *);
int del(nodeL **);