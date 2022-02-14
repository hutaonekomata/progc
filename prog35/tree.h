// Tree型の定義
typedef struct node {  // 空木はNULLポインタ
  int data;            // 整数値がここへ格納される
  int count;           // ノードが持つデータ数
  struct node *left;   // 左部分木へのポインタ
  struct node *right;  // 右部分木へのポインタ
} Tree;

typedef Tree Node;     // 使用場面に応じてTreeとNodeを使い分ける

Tree *getEmptyTree(void);                                // 操作関数①
Tree *createNode(int data);                              // 操作関数②
void setNodeData(Node *node, int data);                  // 操作関数③
int getNodeData(Node *node);                             // 操作関数④
void setSubTree(Node *node, Tree *subtree, char target); // 操作関数⑤
Tree *getSubTree(Node *node, char target);               // 操作関数⑥
Tree **getSubTreeRoot(Node *node, char target);          // 操作関数⑦
int isEmptyTree(Tree *root);                             // 操作関数⑧
int freeNode(Node **node);                               // 操作関数⑨
void rmTree(Tree **root);                                // 操作関数⑩
void printTree(Tree *root);                              // 操作関数⑪

void printTree2(Tree *root);
int getNodeDataN(Node *node);
int setNodeDataN(Node *node,int num);

int mkBalanceTree(Tree **root,int n);
