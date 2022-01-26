#include <stdio.h>
#include <hamakou.h>
#include "list.h"

main()
{
  int data, state, i, n;
  List *head;

  head = getEmptyList(); // headを空リストにする

  n = getint("データの個数："); // リストに格納するデータの個数
  for (i = 1; i <= n; i++) {
    data = getint("Input data: ");  // 新しいセルへ格納するデータの入力
    if (insertUpOrder(&head,data) == 0) {  // 新しいセルの挿入
      fprintf(stderr, "Error: セルを追加できませんでした。\n");
      break;
    }
    printList(head); // リスト構造に格納されているデータの表示
    putchar('\n');
  }
  putchar('\n'); // 見やすくするために改行

  do {
    printList(head); // リスト構造に格納されているデータの表示
    putchar('\n');
  } while (removeHead(&head) == 1);  // 空リストになるまで削除

  return(0);
}
