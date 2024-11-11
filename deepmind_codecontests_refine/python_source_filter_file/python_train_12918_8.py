n,k=map(int,input().split())
 
a=list(map(int,input().split()))
 
b=[(a[i],i) for i in range(n)]
b.sort(reverse=True)

if n==1:
	print(a[0])
	print(1)
	exit()
if k==1:
	print(max(a))
	print(n)
	exit()
ans=0
for i in range(k):
	ans+=b[i][0]
b=b[:k]
 
b.sort(key=lambda x:x[1])
b=[i[1] for i in b]


l=[]
print(ans)

l.append(b[1])
for i in range(1,k-1):
	l.append(b[i]-b[i-1])
l.append(n-b[-1])
print(*l)