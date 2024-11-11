import math
for iter in range(int(input())):
	a,b,c = map(int,input().split())
	print(math.floor((a+b+c)//2))