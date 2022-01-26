#include <stdio.h>
#include <math.h>

typedef struct {
  double x; // x 座標
  double y; // y 座標
} Point;

typedef struct {
  Point p1; // 対角線を表す点1
  Point p2; // 対角線を表す点2
} Rect;

Point ptCreate(double x, double y);
double ptGetX(Point p);
double ptGetY(Point p);

double rctArea(Rect rct);
double rctPerim(Rect rct);
double rctWidth(Rect rct);
double rctHeight(Rect rct);
double rctDiaglen(Rect rct);
Point rctTopLeftCorner(Rect rct);
Rect rctCreate1(Point p1, Point p2);
Rect rctCreate2(Point p, double width, double height);

main()
{
  Rect r;
  Point p1, p2;
  double x1, y1, x2, y2, w, h, s;

  printf("長方形１\n");
  printf("対角線の端点1の座標(x, y)："); scanf("%lg,%lg", &x1, &y1);
  printf("対角線の端点2の座標(x, y)："); scanf("%lg,%lg", &x2, &y2);
  p1 = ptCreate(x1, y1);
  p2 = ptCreate(x2, y2);

  r = rctCreate1(p1, p2); // 長方形の対角線を表す２点で初期化
  putchar('\n');
  printf("左上隅の座標(x, y)：(%g, %g), ",ptGetX(rctTopLeftCorner(r)),ptGetY(rctTopLeftCorner(r)));
  printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));
  putchar('\n');

  printf("長方形２\n");
  printf("左上の点の座標(x, y)："); scanf("%lg,%lg", &x1, &y1);
  p1 = ptCreate(x1, y1);
  printf("横："); scanf("%lg", &w);
  printf("縦："); scanf("%lg", &h);

  r = rctCreate2(p1, w, -h); // 長方形の左上の点と、幅および高さで初期化
  putchar('\n');
  printf("左上隅の座標(x, y)：(%g, %g), ",x1,x2);
  printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));

  return(0);
}

/**
 * @brief
 * 座標(x,y)の点を生成する。
 *
 * @param x
 * @param y
 * @return Point
 */
Point ptCreate(double x, double y){
  Point p;
  p.x = x;
  p.y = y;
  return(p);
}

/**
 * @brief
 * 点pのx座標を返す。
 *
 * @param p
 * @return double
 */
double ptGetX(Point p){
  return( p.x );
}

/**
 * @brief
 * 点pのy座標を返す。
 *
 * @param p
 * @return double
 */
double ptGetY(Point p){
  return( p.y );
}

/**
 * @brief
 * 長方形rctの面積を返す。
 *
 * @param rct
 * @return double
 */
double rctArea(Rect rct){
  return(rctWidth(rct)*rctHeight(rct));
}

/**
 * @brief
 * 長方形rctの周囲の長さを返す
 *
 * @param rct
 * @return double
 */
double rctPerim(Rect rct){
  return( (2 * rctWidth(rct)) + (2 * rctHeight(rct)) );
}

/**
 * @brief
 * 長方形rctの幅の長さを返す
 *
 * @param rct
 * @return double
 */
double rctWidth(Rect rct){
  return( fabs( ptGetX(rct.p1) - ptGetX(rct.p2) ) );
}

/**
 * @brief
 * 長方形rctの高さの長さを返す
 *
 * @param rct
 * @return double
 */
double rctHeight(Rect rct){
  return( fabs( ptGetY(rct.p1) - ptGetY(rct.p2) ) );
}

/**
 * @brief
 * 長方形rctの対角線の長さを返す
 *
 * @param rct
 * @return double
 */
double rctDiaglen(Rect rct){
  return(sqrt(rctWidth(rct)*rctWidth(rct)+rctHeight(rct)*rctHeight(rct)));
}

/**
 * @brief
 *
 * @param rct
 * @return Point
 */
Point rctTopLeftCorner(Rect rct){
  double a,b;
  a = ptGetX(rct.p1);
  if(ptGetX(rct.p2) < a){
    a = ptGetX(rct.p2);
  }
  b = ptGetY(rct.p1);
  if(b < ptGetY(rct.p2)){
    b = ptGetY(rct.p2);
  }
  Point pt;
  pt = ptCreate(a,b);
  return(pt);
}

/**
 * @brief
 *
 * @param p1
 * @param p2
 * @return Rect
 */
Rect rctCreate1(Point p1, Point p2){
  Rect rec;
  rec.p1 = p1;
  rec.p2 = p2;
  return(rec);
}

/**
 * @brief
 *
 * @param p
 * @param width
 * @param height
 * @return Rect
 */
Rect rctCreate2(Point p, double width, double height){
  Rect rct;
  rct = rctCreate1(p,ptCreate(ptGetX(p)+width,ptGetY(p)+height));
  return(rct);
}