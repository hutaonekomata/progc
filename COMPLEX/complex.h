// Complex型の定義
typedef struct {
    double real;  // 実数部
    double imag;  // 虚数部
} Complex;

// 抽象データ型として扱うために必要になる関数群
Complex cAdd(Complex x, Complex y);   // x + y
Complex cSub(Complex x, Complex y);   // x - y
Complex cMul(Complex x, Complex y);   // x * y
Complex cDiv(Complex x, Complex y);   // x / y
void    cPrint(Complex x);            // 複素数の表示
Complex cCreate(double a, double b);  // a + bj の設定
double  cReal(Complex x);             // 実数部の取得
double  cImag(Complex x);             // 虚数部の取得
int cJudge(Complex y);                // 0除算にならないかを確認
double cRad(Complex z);               // 位相角を求める
double cBig(Complex z);               // 複素数から複素数の大きさを求める
