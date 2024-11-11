n,a,b=int(input()),list(map(int,input().split()))+[0],list(map(int,input().split()))+[0]
for i in range(n):
	a[n]^=a[i]
	b[n]^=b[i]
na,nb=sorted(a),sorted(b)
if na!=nb:
	print("-1")
	exit()
f=dict()
def find(x):
	if f[x]==x:
		return x
	else:
		f[x]=find(f[x])
		return f[x]
ans=0
for i in range(n):
	if a[i]!=b[i]:
		f[a[i]]=a[i]
f[a[n]]=a[n]
for i in range(n):
	if a[i]!=b[i]:
		ans+=1
		f[find(b[i])]=find(a[i])
for i,j in f:
	if i==j:
		ans+=1
print(ans-1)