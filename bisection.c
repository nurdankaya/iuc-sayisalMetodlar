
//Programın amacı: x3-7x2+14x-6=0 fonksiyonunun [0,1] aralığındaki kökünü yarılama yöntemine göre bulan bir C programı yazınız.
//Program çalışması sonucunda ekranda” iterasyon sayısı, a, b, p, f(p)” değerleri alt alta yazdırılacaktır. 

#include <stdio.h>

int main() {

	float p, fp, fa;
	float a, b; // [a,b] interval
	int c, d, e , f; // cx^3 + dx^2 + rx + f
	int i = 0;
	a = 0, b = 1;
	c = 1, d = -7, e = 14, f = -6;
	p = (a + b) / 2;
	fa = c * a * a * a + d * a * a + e * a + f;
	printf("i    a            b             p           f(p)\n");
	while (1) {
		p = (a + b) / 2;
		fp = c * p * p * p + d * p * p + e * p + f;
		printf("%d   %.4f      %.4f      %.4f      %f\n", i,a, b, p, fp);
		if (fp == 0.0 || (double(b) - a) < 0.001) {
			return 0;
		}
		i = i + 1;
		if (fa * fp > 0) {
			a = p;
			fa = fp;
		}
		else
			b = p;
	}
	return 0;
}
