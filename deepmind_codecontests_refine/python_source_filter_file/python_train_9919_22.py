import math

for cases in range(int(input())):
	total, x = map(int,input().split())
	if total<3:
		print(total)
	else:
		print(int(math.ceil((total-2)/x))+1)