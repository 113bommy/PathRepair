[n, p] = [int(x) for x in input().split()]
a = []
b = []
for i in range(n):
	inp = [int(x) for x in input().split()]
	if(inp[1]>inp[0]):
		a.append(inp[0])
		b.append(inp[1])
	else:
		a.append(inp[1])
		b.append(inp[0])
a.sort()
b.sort()
if(a[n-1]>b[0]):
	print(-1)
if(p>=a[n-1] and p<=b[0]):
	print(0)
elif(p<a[n-1]):
	print(a[n-1]-p)
elif(p>b[0]):
	print(p-b[0])