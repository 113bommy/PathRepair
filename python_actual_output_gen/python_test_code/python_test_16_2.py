# your code goes here
n = int(input())
for i in range(n):
	ans=0
	a = {i:int(x) for i,x in enumerate(input().split())}
	b = {i:int(x) for i,x in enumerate(input().split())}
	val = min(a[2],b[1])
	b[1] = b[1]-val
	ans+=2*val
	val2 = min(a[1],b[0]+b[1])
	a[1] = a[1] - val2
	ans = ans-a[1]
	print(ans)