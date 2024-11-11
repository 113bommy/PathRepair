import math
for iter in range(int(input())):
	a,b,c = map(int,input().split())
	print(math.ceil((a+b+c)/2))