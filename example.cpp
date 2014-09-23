#include <cstdio>
#include <cstdlib>

class Strom {
	int from, mid, to;
	int sucet;
	Strom* l;
	Strom* r;
 public:
	Strom(int a, int b) {
		sucet = 0;
		from = a;
		to = b;
		mid = (a + b) / 2;
		if (b > a + 1) {
			l = new Strom(a, mid);
			r = new Strom(mid, b);
		}
	}
	void Set(int kde, int kolko) {
		if (kde < from || kde >= to)
			return;
		if (to == from + 1) {
			sucet = kolko;
			if (from != kde) {
				printf("Tragical error %d %d %d    %d %d\n", from, mid, to, kde, kolko);
				exit(0);
			}
		} else {
			l->Set(kde, kolko);
			r->Set(kde, kolko);
			sucet = l->sucet + r->sucet;
		}
	}
	int Sucet(int a, int b) {
		if (a <= from && b >= to)
			return sucet;
		if (b <= from || a >= to)
			return 0;
		return l->Sucet(a, b) + r->Sucet(a, b);
	}
};

int main() {
	int size = 10;
	Strom s(0, 10);
	s.Set(1, 1);
	s.Set(3, 1);
	s.Set(8, 1);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			printf("%2d %2d %2d\n", i, j, s.Sucet(i, j));
		}
	}
}
