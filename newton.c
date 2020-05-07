#include <stdio.h>

int main() {

	float p0, p, fp, fa;
	float a, b; // [a,b] interval
	int c, d, e, f; // cx^3 + dx^2 + rx + f
	int i = 0;
	a = 0, b = 1;
	c = 1, d = -7, e = 14, f = -6;
	p0 = 0.5;
	fa = c * a * a * a + d * a * a + e * a + f;
	printf("i            p           f(p)\n");
	while (1) {
		p = p0 - (c * p0 * p0 * p0 + d * p0 * p0 + e * p0 + f) / (3 * p0 * p0 - 14 * p0 + 14);

		printf("%d       %.4f         %.4f \n ", i, p0, p);
		if ((p - p0) < 0.001) {
			return 0;
		}
		i = i + 1;
		p0 = p;
	}
	return 0;
}