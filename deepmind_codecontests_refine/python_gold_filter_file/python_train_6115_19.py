n,m=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
a=[-1]*10
b=[]
for i in range(m):
	if y[i] in x:
		a[x.index(y[i])]=y[i]
for i in range(len(a)):
	if a[i]!=-1:
		b.append(a[i])
print(*b)