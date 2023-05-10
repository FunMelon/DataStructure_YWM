// 通过本例子深刻体会ADT的基本概念
typedef struct {   // 复数类型
  float Realpart;  // 实部
  float Imagepart; // 虚部
} Complex;

// 构造一个复数
void Create(Complex &C, float x, float y) {
  C.Realpart = x;
  C.Imagepart = y;
}

// 取复数的实部
float GetReal(Complex C) { return C.Realpart; }

// 取复数的虚部
float GetImag(Complex C) { return C.Imagepart; }

// 求两个复数的和
Complex Add(Complex C1, Complex C2) {
  Complex sum;
  sum.Realpart = C1.Realpart + C2.Realpart;
  sum.Imagepart = C1.Imagepart + C2.Imagepart;
  return sum;
}

// 求两个复数的差
Complex Sub(Complex C1, Complex C2) {
  Complex difference;
  difference.Realpart = C1.Realpart - C2.Realpart;
  difference.Imagepart = C1.Imagepart - C2.Imagepart;
  return difference;
}
