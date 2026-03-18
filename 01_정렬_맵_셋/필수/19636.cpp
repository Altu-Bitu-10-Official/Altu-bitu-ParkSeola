#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Diet
{
	int weight, bmr, amr,
		diet_ener, t, diet_day;
};

string diet1(Diet& d) {
	int weight = d.weight;
	for (int i = 0; i < d.diet_day; i++) {
		weight += d.diet_ener - d.bmr - d.amr;
		if (weight <= 0) {
			return "Danger Diet";
		}
	}
	return to_string(weight) + " " + to_string(d.bmr);
}

string diet2(Diet& d) {
	int over_t;
	int start_weight = d.weight;
	int bmr = d.bmr;
	string state;

	for (int i = 0; i < d.diet_day; i++) {
		over_t = d.diet_ener - bmr - d.amr;
		d.weight += over_t;
		if (abs(over_t) > d.t) {
			bmr += floor((double)over_t / 2);
		}
		if (d.weight <= 0 || bmr <= 0) {
			return "Danger Diet";
		}

	}



	state = (bmr < d.bmr) ? "YOYO" : "NO";
	return to_string(d.weight) + " " + to_string(bmr) + " " + state;


}

int main()
{
	Diet d;

	cin >> d.weight >> d.bmr >> d.t;
	cin >> d.diet_day >> d.diet_ener >> d.amr;

	cout << diet1(d) << '\n';

	cout << diet2(d);




	return 0;
}