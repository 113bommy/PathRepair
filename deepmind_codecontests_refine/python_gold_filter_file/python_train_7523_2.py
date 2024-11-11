n=int(input())
g={0}
ans=0
cs=0
for i in map(int,input().split()):
	cs+=i
	if cs in g:
		g={0,i}
		ans+=1
		cs=i
	else:g.add(cs)
print(ans)