import math
t = int(input())
for hello in range(t):
	a,b,c = list(map(int,input().split()))
	res = [-1,-1]
	if c < a*b:
		res[1] = b
	if a < b:
		res[0] = 1
	print(res[0], res[1])
