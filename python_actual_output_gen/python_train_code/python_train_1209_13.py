n = int(input(""))
k = int(input(""))
a = int(input(""))
b = int(input(""))

ans = 0
while not n == 1:
	m = n % k
	n = n - m
	ans = ans + m*a

	if (n-(n/k))*a > b:
		n = n / k
		ans = ans + b
	else:
		ans = ans + (n-1)*a
		n = 1
print(int(a)) 
"""
	int64 ans = 0;
	while(n != 1){
		int64 m = n % k;
		n -= m;
		//cout << "m " << m << endl;
		ans += m*a;

		if((n-(n/k))*a > b){
			n /= k;
			ans += b;
		}else{
			ans += (n-1)*a;
			cout << ans;
			return 0;
		}

	}	
	
	cout << ans;
"""