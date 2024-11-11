n=int(input())
d=[[-1e9-1, 0]]
for i in range(n):
	d.append(list(map(int, input().split())))
d.append([2*1e9+2, 0])
c=-1e9-1
ans=0
for i in range(1, n+1):
	x=d[i][0]
	h=d[i][1]
	if x-h>c:
		ans+=1
		c=x-h
	elif x+h<d[i+1][0]:
		ans+=1
		c=x+h
	else: c=x
print(ans)


