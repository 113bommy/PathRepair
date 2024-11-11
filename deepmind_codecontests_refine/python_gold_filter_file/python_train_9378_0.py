n=int(input())
a=list(map(int,input().split()))
b=set()
c=[]
s=0
for i in a:
	if not i in b:
		s+=1
		b.add(i)
	c.append(s)
b=set()
ans=0
for i in range(n-1,0,-1):
	if not a[i] in b:
		ans+=c[i-1]
		b.add(a[i])
print(ans)