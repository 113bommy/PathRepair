import sys

f=sys.stdin

n=int(f.readline())
s=[f.readline().strip() for i in range(n)]
s=[(x,x.count('s'),x.count('h')) for x in s]
s=sorted(s,key=lambda x:-x[1]/(x[2]+0.0001))
s=''.join(x[0] for x in s)
ans,tmp=0,0
for x in s:
	if x=='h':
		ans+=tmp
	else:
		tmp+=1
print(ans)