n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [0] * 101

for x in range(m):
	b[a[x]] += 1
b.sort(reverse=True)
# print(b)
for x in range(101,1,-1):
	temp = 0
	for y in range(len(b)):
		temp += b[y]//x
	if(temp >= n):
		print(x)
		exit(0)
print(-1)