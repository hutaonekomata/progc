//
//  木から指定した値を持つノードをすべて削除するプログラム
//  （注：このプログラムでは、削除した結果バランス木はくずれる）
//
#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "tree.h"

int rmSearchNodeAll(Tree **root, int target);
Tree **mostLeftLeafRoot(Tree **root);

Tree *origin;

main()
{
    Tree *root;
    int n, x, stat;

    n = getint("ノードの数: ");                 // ノードの総数を入力
    stat = mkBalanceTree(&root, n);             // ノード数ｎのバランス木を作る
    origin  = root;
    putchar('\n');                              // 見やすくするために改行
    printf("stat: %d\n\n", stat);               // 正しく作られたか戻り値を確認
    printTree(root);                            // バランス木の表示
    putchar('\n');                              // 見やすくするために改行
    do {
        x = getint("削除データ: ");             // 削除するデータの値を入力
        stat = rmSearchNodeAll(&root, x);       // 削除に成功すれば       1
        putchar('\n');                          // 見やすくするために改行
        printf("stat = %d\n\n", stat);          // データが存在しなければ 0
        printTree(root);                        // バランス木の表示
        putchar('\n');                          // 見やすくするために改行
    } while (!isEmptyTree(root));               // 全ノードを削除するまで繰り返す

    return(0);
}

//-------------------------------------------------------------------------------
//  木から指定した値を持つノードをすべて削除する
//  ［引　数］root   : 削除対象の木のルートへのポインタ
//            target : 削除する整数データ
//
//  ［戻り値］target が存在し、削除が成功したとき     : 1
//            target がが存在せず、削除に失敗したとき : 0
//-------------------------------------------------------------------------------
int rmSearchNodeAll(Tree **root, int target)
{
    Tree *rm_node, **most_left;

    if (isEmptyTree(*root)) { // 指定した値を持つノードは存在しない
        return(0);
    } else{
        int n;
        if (getNodeData(*root) == target) {
            // 指定した値を持つノードが見つかった
            rm_node = *root;
            if (isEmptyTree(getSubTree(*root, 'R'))) {
                // 見つかったノードの右部分木が空木なので、このノードの左部分木でつなぎ替える
                root =  getSubTreeRoot(*root,'L');
                freeNode(&rm_node);
            } else if (isEmptyTree(getSubTree(*root, 'L'))) {
                // 見つかったノードの左部分木が空木なので、このノードの右部分木でつなぎ替える
                root =  getSubTreeRoot(*root,'R');
                freeNode(&rm_node);
            } else {
                // 見つかったノードは２つの子を持つので、最左端のノードと交換
                most_left = mostLeftLeafRoot(root);
                setNodeData(*root,getNodeData(*most_left));
                freeNode(most_left);
            }
            if(!isEmptyTree(*root)){
                n = rmSearchNodeAll(root,target);
            }
        }
        if(!isEmptyTree(*root)){
            // 指定した値を持つノードを左部分木から探す
            int r,l;
            r = rmSearchNodeAll(getSubTreeRoot(*root,'R'),target);
            l = rmSearchNodeAll(getSubTreeRoot(*root,'L'),target);
            if(r || l || n){
                return(1);
            } else {
                return(0);
            }
        }else{
            return(0);
        }
    }
}
//-------------------------------------------------------------------------------
//  最左端のリーフを指すポインタを保持している領域のアドレスを取得する
//  ［引　数］root : 最左端を探す対象となる木のルートを指すポインタ
//  ［戻り値］最左端のリーフを指すポインタを保持している領域のアドレス
//            ただし、rootが空リストのときはNULLポインタ
//-------------------------------------------------------------------------------
Tree **mostLeftLeafRoot(Tree **root)
{
    if (isEmptyTree(*root)) {
        return(NULL);
    } else if (isEmptyTree(getSubTree(*root,'L')) && isEmptyTree(getSubTree(*root,'R'))) {
        // (*root)がリーフのとき
        return(root);
    } else if (isEmptyTree(getSubTree(*root, 'L'))) {
        // (*root)が左部分木を持たないとき
        return(mostLeftLeafRoot(getSubTreeRoot(*root,'R')));
    } else {
        // (*root)が左部分木を持つとき
        return(mostLeftLeafRoot(getSubTreeRoot(*root,'L')));
    }
}
