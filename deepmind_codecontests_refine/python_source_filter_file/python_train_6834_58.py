import math
k=int(input())
if k>36:
	print(-1)
else:
	for i in range(k//2):
		print(8, end="")
	if k%2 != 0:
		print(0,end="")
print("")