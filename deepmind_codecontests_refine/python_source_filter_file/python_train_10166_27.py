import math

p,y = [int(x) for x in input().split()]

def check(x):
	mx = int(math.sqrt(x)) + 1
	for i in range(2,min(p,mx)):
		if x % i == 0:
			return False
	return True

ans = -1

for x in range(max(p + 1,y - 300),y):
	if check(x):
		ans = x

print(ans)
	



