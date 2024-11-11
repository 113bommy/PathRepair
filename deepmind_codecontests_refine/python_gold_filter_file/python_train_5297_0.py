# AOJ 0112: A Milk Shop
# Python3 2018.6.18 bal4u

while True:
	n = int(input())
	if n == 0: break
	f = [0]*65
	for i in range(n):
		f[int(input())] += 1
	if n == 1:
		print(0)
		continue
	n -= f[0]
	i, ans, m = 1, 0, n
	while m > 0:
		k = f[i];
		if k == 0:
			i += 1
			continue
		if k == 1: ans += (m-1)*i
		else: 
			a = m*k - (k*(k+1))//2
			ans += a*i;
		m -= k;
		i += 1
	print(ans)
