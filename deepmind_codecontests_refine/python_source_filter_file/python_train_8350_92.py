t = int(input())

print(t)
for i in range(t):
	h, m = [int(j) for j in input().split()]

	total = 24*60
	print(total - h*60-m)
