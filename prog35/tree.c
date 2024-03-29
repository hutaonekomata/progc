#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"

void printTreeSub(Tree *root, int depth);
void printTree2Sub(Tree *root, int depth);

// #define HomeWorking

#ifndef HomeWorking

#include <hamakou.h>

#else

int getint(char *c){
  printf("%s",c);
  int a;
  scanf("%d",&a);
  return(a);
}

#endif

//-------------------------------------------------------------------------------
// ① 空木を取得する
//  ［引　数］なし
//  ［戻り値］空木へのポインタ(Tree *)NULL
//-------------------------------------------------------------------------------
Tree *getEmptyTree(void)
{
  return (Tree *)NULL;
}

//-------------------------------------------------------------------------------
// ② 新しいノードを１つ作る
//  ［引　数］data  : 作ったノードに格納する整数値
//  ［戻り値］ノードが正しく作れたとき　：　作られたノードへのポインタ
//  　　　　　ノードの生成に失敗したとき：　空木
//-------------------------------------------------------------------------------
Node *createNode(int data)
{
  Node *new;
  new = (Node *)malloc(sizeof(Node) * 1);
  if(new == getEmptyTree()){
    return(getEmptyTree());
  }
  setNodeData(new,data);
  setNodeDataN(new,1);
  // new->left = getEmptyTree();
  // new->right = getEmptyTree();
  setSubTree(new,getEmptyTree(),'L');
  setSubTree(new,getEmptyTree(),'R');
  return new;
}

//-------------------------------------------------------------------------------
// ③ 指定したノードにデータを格納する（既存のデータを更新する）
//  ［引　数］node : 操作対象となるノードへのポインタ
//            data : ノードへ格納する整数値
//  ［戻り値］なし
//-------------------------------------------------------------------------------
void setNodeData(Node *node, int data)
{
  node->data = data;
  return;
}

/**
 * @brief Set the Node Data how many in object
 *
 * @param node
 * @param num
 *
 */
int setNodeDataN(Node *node,int num){
  node->count = num;
  return node->count;
}

//-------------------------------------------------------------------------------
// ④ 指定したノードのデータを取り出す
//  ［引　数］node : 操作対象となるノードへのポインタ
//  ［戻り値］取り出した整数値
//-------------------------------------------------------------------------------
int getNodeData(Node *node)
{
  return node->data;
}

/**
 * @brief Get the Node Data how many in object
 *
 * @param node
 * @return int
 */
int getNodeDataN(Node *node){
  return node->count;
}

//-------------------------------------------------------------------------------
// ⑤ 指定したノードの左または右部分木に新たな部分木を格納する
//  ［引　数］cell    : 操作対象となるノードへのポインタ
//            subtree : 格納する部分木のポインタ
//            target  : 部分木の格納位置を指定する文字
//  ［戻り値］なし
//  ［機　能］targetが 'L' または 'l' のとき：subtreeを左部分木に格納する
//   　　　　 targetが 'R' または 'r' のとき：subtreeを右部分木に格納する
//   　　　　 targetが 'L','l','R','r' 以外のときは何もしない
//-------------------------------------------------------------------------------
void setSubTree(Node *node, Tree *subtree, char target)
{
  if(target == 'L' || target == 'l'){
    node->left = (Tree *)malloc(sizeof(Tree) * 1);
    node->left = subtree;
  }else if(target == 'R' || target == 'r'){
    node->right = (Tree *)malloc(sizeof(Tree) * 1);
    node->right = subtree;
  }
  return;
}

//-------------------------------------------------------------------------------
// ⑥ 指定したノードにつながる部分木のポインタを取り出す
//  ［引　数］node  : 操作対象となるセルへのポインタ
//            target: 取り出したい部分木を指定する文字
//  ［戻り値］target = 'L' または 'l' のとき　　  : 左部分木を指すポインタ
//  　　　　　target = 'R' または 'r' のとき　　  : 左部分木を指すポインタ
//  　　　　　target = 'L','l','R','r' 以外のとき : NULLポインタ
//-------------------------------------------------------------------------------
Tree *getSubTree(Node *node, char target)
{
  if(target == 'L' || target == 'l'){
    return node->left;
  }else if(target == 'R' || target == 'r'){
    return node->right;
  }
  return getEmptyTree();
}

//-------------------------------------------------------------------------------
// ⑦ 指定したノードの左または右部分木を指すポインタを保持しているメンバ
//   変数のアドレスを取得する
//  ［引　数］node  : 操作対象となるノードへのポインタ
//            target: 取り出したい部分木を指定する文字
//  ［戻り値］target = 'L' または 'l' のとき
//  　　　　　　　　　 左部分木のポインタを保持するメンバ変数のアドレス
//  　　　　　target = 'R' または 'r' のとき
//  　　　　　　　　　 右部分木のポインタを保持するメンバ変数のアドレス
//  　　　　　target = 'L','l','R','r' 以外のときはNULLポインタを返す
//-------------------------------------------------------------------------------
Tree **getSubTreeRoot(Node *node, char target)
{
  if(isEmptyTree(node)){
    Tree **ret = (Tree **)malloc(sizeof(Tree *) * 1);
    *ret = (Tree *)malloc(sizeof(Tree) * 1);
    *ret = getEmptyTree();
    return(ret);
  }
  if(target == 'L' || target == 'l'){
    return &(node->left);
  }else if(target == 'R' || target == 'r'){
    return &(node->right);
  }
  Tree **ret = (Tree **)malloc(sizeof(Tree *) * 1);
  *ret = (Tree *)malloc(sizeof(Tree) * 1);
  *ret = getEmptyTree();
  return(ret);
}

//-------------------------------------------------------------------------------
// ⑧ 与えられた木が空木かどうか調べる
//  ［関　数］int isEmptyTree(Tree *root);
//  ［引　数］root : 木の根を指すポインタ
//  ［戻り値］rootが空木のとき　　：１
//  　　　　　rootが空木でないとき：０
//-------------------------------------------------------------------------------
int isEmptyTree(Tree *root)
{
  if(root == getEmptyTree()){
    return 1;
  }else{
    return 0;
  }
}

//-------------------------------------------------------------------------------
// ⑨ 指定したノードのメモリ領域を解放する
//  ［引　数］node：解放対象ノードへのポインタを格納している領域のアドレス
//  ［戻り値］空木でないノードを解放したとき：　１
//  　　　　　指定したノードが空木だったとき：　０
//  ［機　能］nodeで指定するノードのメモリ領域を解放する。メモリの解放後
//　　　　　　引数で渡されたnodeは空木にする。メモリを解放するのみで、
//　　　　　　枝のつなぎ替えは行わない。また、空木のときは何もしない。
//-------------------------------------------------------------------------------
int freeNode(Node **node)
{
  free(*node);
  *node = NULL;
  return 1;
}

//-------------------------------------------------------------------------------
// ⑩ 指定した二分木のノードをすべて削除する
//  ［引　数］root : 木の根を指すポインタを格納している領域のアドレス
//  ［戻り値］なし
//  ［機　能］rootで指定した木のノードをすべて削除する
//-------------------------------------------------------------------------------
void rmTree(Tree **root)
{
  if (!isEmptyTree(*root)) {
    rmTree(getSubTreeRoot(*root, 'R'));
    rmTree(getSubTreeRoot(*root, 'L'));
    freeNode(root);
  }
  // freeNode(root);
  return;
}

//-------------------------------------------------------------------------------
// ⑪ 与えられた二分木を表示する
//  ［関　数］void printTree(Tree *root);
//  ［引　数］root : 木の根を指すポインタ
//  ［戻り値］なし// 二分木の表示
//-------------------------------------------------------------------------------
void printTree(Tree *root)
{
  printTreeSub(root, 0);
  return;
}

//-------------------------------------------------------------------------------
// 与えられた二分木を表示する（printTree()から呼び出すサブ関数）
//  ［関　　数］void printTree(Tree *root);
//  ［第１引数］root  : 木の根を指すポインタ
//  ［第２引数］depth : 表示対象部分木のレベル
//  ［戻 り 値］なし
//-------------------------------------------------------------------------------
void printTreeSub(Tree *root, int depth)
{
  int i;

  if (!isEmptyTree(root)) {
    printTreeSub(getSubTree(root, 'R'), depth + 1);
    for (i = 0; i < depth; i++) {
      printf("   ");
    }
    printf("%d\n", getNodeData(root));
    printTreeSub(getSubTree(root, 'L'), depth + 1);
  }
  return;
}

/**
 * @brief
 *
 * @param root
 */
void printTree2(Tree *root)
{
  printTree2Sub(root, 0);
  return;
}

/**
 * @brief
 *
 * @param root
 * @param depth
 */
void printTree2Sub(Tree *root, int depth)
{
  int i;

  if (!isEmptyTree(root)) {
    printTree2Sub(getSubTree(root, 'R'), depth + 1);
    for (i = 0; i < depth; i++) {
      printf("   ");
    }
    printf("%d[%d]\n", getNodeData(root),getNodeDataN(root));
    printTree2Sub(getSubTree(root, 'L'), depth + 1);
  }
  return;
}

//-------------------------------------------------------------------------------
// バランス木を生成する
//   [引　数］root：木の根を指すポインタを格納している領域のアドレス
//            n   ：ノードの総数
//  ［戻り値］木を正しく生成できたとき：　１
//            木の生成に失敗したとき　：　０
//  ［機　能］整数値を格納するｎ個のノードからなるバランス木を生成する。
//            各ノードに格納するデータは、ノードを作る際にキーボードより入力する
//            木の生成が途中で失敗したときは、そこで生成を中止する
//           （途中まで作られた木はそのまま残す）
//-------------------------------------------------------------------------------
int mkBalanceTree(Tree **root, int n)
{
  if(n<=0){
    *root = getEmptyTree();
    return(1);
  }
  int num;
  num = getint("ノードへ格納する値 : ");
  *root = createNode(num);
  if(isEmptyTree(*root)){
    return(0);
  }
  return(mkBalanceTree(getSubTreeRoot(*root,'L'),n/2) && mkBalanceTree(getSubTreeRoot(*root,'R'),n-n/2-1) );
}
