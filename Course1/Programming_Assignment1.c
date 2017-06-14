#include<bits/stdc++.h>
using namespace std;

string multiply(string n1, string n2)
{
	int l1 = n1.size();
	int l2 = n2.size();
	if (l1 == 0 || l2 == 0)
	return "0";

	vector<int> result(l1 + l2, 0);

	int m = 0; 
	int n = 0; 

	for (int i= l1 - 1; i>= 0; i--)
	{
		int carry = 0;
		int l1 = n1[i] - '0';

		n = 0; 
		
		for (int j= l2-1; j>=0; j--)
		{
			
			int l2 = n2[j] - '0';

			int sum = l1*l2 + result[m + n] + carry;
			carry = sum/10;

			result[m + n] = sum % 10;

			n++;
		}

		if (carry > 0)
			result[m + n] += carry;

		m++;
	}

	int i = result.size() - 1;
	while (i>=0 && result[i] == 0)
	i--;
	
	if (i == -1)
	return "0";

	string s = "";
	while (i >= 0)
		s += to_string(result[i--]);

	return s;
}

int main()
{
	string s1 = "3141592653589793238462643383279502884197169399375105820974944592";
	string s2 = "2718281828459045235360287471352662497757247093699959574966967627";
	cout << multiply(s1, s2);
	return 0;
}
