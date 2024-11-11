n = int(input())
sum = 0
for i in range(n, 0, -1):
	sum += (i-1)/i
print(float(sum + 1))
