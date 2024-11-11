import bisect
_=input()
a=sorted([int(i)for i in input().split()])
for _ in range(int(input())):
	print(bisect.bisect(a,int(input())))