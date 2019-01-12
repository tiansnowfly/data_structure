#include <iostream>
using namespace std;

struct node {
	int power;
	int scores;
	int number;
};
node *arr = new node[62];
class proque {
	int size;
	node *elem;
	int len;
	void preDown(int hole);
	void buildHeap();
public:
	proque(int sz = 10) {
		size = sz;
		len = 0;
		elem = new node[sz];
	}
	~proque() { delete[] elem; }
	void push(const node &nd) {
		int hole = ++len;
		for (; hole > 1 && elem[hole / 2].scores<= nd.scores; hole /= 2){
			if(elem[hole/2].scores<nd.scores)elem[hole] = elem[hole / 2];
			else {
                if(elem[hole/2].number>nd.number) elem[hole]=elem[hole/2];
			}
		}
		elem[hole] = nd;
	}
	node pop() {
		node max_x = elem[1];
		elem[1] = elem[len--];
		preDown(1);
		return max_x;
	}
	bool isEmpty() const { return len == 0; }
};
void proque::buildHeap() { for (int k = len / 2; k > 0; --k) preDown(k); }
void proque::preDown(int hole) {
	int child;
	node tmp = elem[hole];
	for (; hole * 2 <= len; hole = child) {
		child = 2 * hole;
		if (child != len && elem[child + 1].scores >= elem[child].scores){
            if(elem[child + 1].scores > elem[child].scores)++child;
            else {if(elem[child + 1].number < elem[child].number)++child;}
		}
		if (tmp.scores <= elem[child].scores){
            if(tmp.scores<elem[child].scores)elem[hole] = elem[child];
            else {if(tmp.number>elem[child].number)elem[hole]=elem[child];}
		}
		else break;
	}
	elem[hole] = tmp;
}

int N, R;

int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int I;

	proque q(62),q0(62);

	cin >> N >> R;

	for (I = 1; I <= 2*N; ++I) {

		cin >> arr[I].scores;

		arr[I].number = I;


	}

	for (I = 1; I <= 2*N; ++I) {cin >> arr[I].power;q.push(arr[I]);}

	node mice1, mice2;

	while (R--) {

		while(!q.isEmpty()){

			mice1 = q.pop();

			mice2 = q.pop();

			if (mice1.power > mice2.power)mice1.scores += 2;

			else if (mice1.power == mice2.power) { ++mice1.scores; ++mice2.scores; }

			else mice2.scores += 2;

			q0.push(mice1);

			q0.push(mice2);

		}

		while (!q0.isEmpty()) {

			q.push(q0.pop());

		}

	}

	node ans;

	while (!q.isEmpty()) {

		ans = q.pop();

		cout << ans.number << " ";

	}

	delete [] arr;

	return 0;

}
