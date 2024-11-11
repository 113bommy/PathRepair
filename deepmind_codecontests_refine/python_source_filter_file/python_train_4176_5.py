n, m, k = map(int, input().split())
s = n*m / k

def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)


if s % 0.5 == 0:
	f = True
	if(k % 2 == 0):
		k //= 2
		f = False
	
	print("YES")
	a = n / gcd(n, k)
	b = m*gcd(n, k) / k

	if(f):
		if(a < n): a *= 2;
		else: b *= 2;

	print(0,0)
	print(0,int(b))
	print(int(a),0)

else:
	print("NO")
