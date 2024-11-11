t = int(input())
for i in range(t):
	n,m = list(map(int,input().split()))
	if m > n and m % n == 0:
		print('YES')
	else:
		print('NO')