n = int(input())
a = [int(v) for v in input().split()]
x = [[] for _ in range(64)]
for i, v in enumerate(a):
	mask = 1
	for k in range(64):
		if (v & mask):
			x[k].append(i)
		mask <<= 1
z = 0
for k in range(63,0,-1):
	if len(x[k]) == 1:
		z = x[k][0]
		break
print(a[z], *(a[:z]+a[z+1:]))