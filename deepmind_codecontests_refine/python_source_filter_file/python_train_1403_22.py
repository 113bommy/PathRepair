n,k=[int(x)for x in input().split()]
l = []
ans = []
i = 0
for x in input().split():
	l.append((int(x),i))	
	i+=1
l.sort()
counter = 0
while k > 0 and counter < len(l):
	k-= l[counter][0]
	ans.append(l[counter][1])
	counter+=1
if k < 0:
	counter-=1
	ans.pop()
print(counter)
print(*ans)

