'''
	Go Beyond
		Plus
			Ultra
	PJ28105
'''
n,m = list(map(int,input().split()))
a = list(map(int,input().split()))
if n >= m:
	print(0)
else:
	ans = 1
	for i in range(n):
		for j in range(i+1,n):
			ans = (abs(a[i] - a[j]) * ans) % m
	print(ans)