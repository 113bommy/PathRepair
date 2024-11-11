m, s = list(map(int,input().split()))
arr = [0]*m
i = 0
if s==0 and m == 1:
	print(0,0)
elif s==0 or s>9*m:
	print(-1 -1)
else:
	print(10**(m-1) + sum(10**(i//9) for i in range(s-1)),
		sum(10**(m-1-i//9) for i in range(s)))
		