# import sys
# sys.stdin = open("F:\\Scripts\\input","r")
# sys.stdout = open("F:\\Scripts\\output","w")


MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
t, = I()
while t:
	t -= 1
	n , m , k = I()
	mi = min(n,m)
	ma = max(n,m)
	if k < ma:
		print(-1)
	else:
		d = mi
		rem = k - d
		tob = ma - d
		if rem%2 == 0 and tob%2 == 0:
			print(k)
		elif tob%2:
			print(k - 1)
		else:
			print(k - 2)

