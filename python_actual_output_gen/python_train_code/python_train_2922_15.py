import math
n = int(input())
curday = 1
for i in range(n):
	inf = list(map(int,input().split()))
	k = math.ceil((curday-inf[0])/inf[1])
	if k<0: k=0
	curday = inf[0]+k*inf[1] + 1
print(curday)
