n,k = [int(x) for x in input().split()]
d = []
for i in range(n):
	d.append([int(x) for x in input().split()])
d.sort(key=lambda k: (k[0], -k[1]), reverse=True)
j = k-1
x = d[k-1]
c = 0
while j<n:
	if d[j][0]==x[0] and d[j][1]==x[1]:
		c+=1
	else:
		break
	j+=1
j = k-2
while j>=0:
	if d[j][0]==x[0] and d[j][1]==x[1]:
		c+=1
	else:
		break
	j-=1
print(c)