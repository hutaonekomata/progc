#define QUEUE_SIZE 10
// #define QUEUE_SIZE 1010

typedef struct {
  int strage[QUEUE_SIZE];  // 整数データを格納する配列
  int head;                 // 次に取り出すデータの位置
  int tail;                 // 次にデータを格納する位置
} Queue;

void initQueue(Queue *q);
int enQueue(Queue *q, int data);
int deQueue(Queue *q, int *data);
