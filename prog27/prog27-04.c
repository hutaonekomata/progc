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
    if (insertHead(&head,data) == 0) {  // 新しいセルの挿入
      fprintf(stderr, "Error: セルを追加できませんでした。\n");
      break;
    }
  }

  putchar('\n');     // 見やすくするために改行
  printf("削除前: ");
  printList(head);   // リスト構造に格納されているデータの表示
  putchar('\n');

  removeList(&head); // リスト全体を削除

  printf("削除後: ");
  printList(head);   // 削除されたことを確認
  putchar('\n');

  return(0);
}
