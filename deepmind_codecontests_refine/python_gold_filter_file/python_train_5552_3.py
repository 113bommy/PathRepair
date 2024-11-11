n = int(input())
a = []
 
for i in range(n):
	a.append(list(map(int, input().split()))[::-1])
 
a.sort(reverse=True)
p = 0
c = 1
i = 0
while c > 0 and i < n:
	p += a[i][1]
	c -= 1
	c += a[i][0]
	i += 1
print(p)