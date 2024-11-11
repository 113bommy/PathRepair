q = int(input())
while(q > 0):
	q -= 1
	n , k = map(int , input().split())
	a = list(map(int , input().split()))
	a.insert(0 , 0)
	res = 1
	u = 0
	p = [0] * (n + 5)
	for i in range(2 , n):
		if(a[i - 1] < a[i] and a[i] > a[i + 1]):
			p[i] = p[i - 1] + 1
		else:
			p[i] = p[i - 1]
	for i in range(1 , n + 1):
		if(i + k - 1 > n):
			break;
		if(res < p[i + k - 2] - p[i]):
			res = p[i + k - 2] - p[i]
			u = i
	print(res + 1 , u)
			