
struct nodeQ {
	int val;
	nodeQ *sled;
};

void QueueMenu();
void add(nodeQ **, nodeQ **);
void print(nodeQ *);
int del(nodeQ **);

