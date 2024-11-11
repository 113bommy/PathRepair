a,b,c=map(int,input().split())
s=list(map(str,input().split()))
x=list(map(int,input().split()))
d={}
for i in range(a):
	d[s[i]]=x[i]
for i in range(b):
	y=list(map(int,input().split()))
	l=y[1]
	for j in range(y[0]):
		d[s[l-1]]=min(x[y[j+1]-1],x[l-1])

	for j in range(y[0]):
		d[s[y[j+1]-1]]=d[s[l-1]]

z=list(map(str,input().split()))
sumx=0
for i in range(len(z)):
	sumx+=d[z[i]]
print(sumx)


