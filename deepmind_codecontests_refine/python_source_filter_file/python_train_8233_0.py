
n,m=map(int,input().split())
if m==1:
	ar=list(map(int,input().split()))
	print((n*(n+1))//2)
	exit()
ar=list(map(int,input().split()))
dd=dict(zip(zip(ar,ar[1:]),[1]*(n-1)))
for v in range(m-2):
	ar=list(map(int,input().split()))
	a=ar[0]
	for i in range(1,n-1):
		b=ar[i]
		if (a,b) in dd:
			dd[(a,b)]+=1
		a=b
m-=1
ar=list(map(int,input().split()))
a=ar[0]
bo=False
l=2
s=0
for i in range(1,n):
	b=ar[i]
	if (a,b) in dd and dd[(a,b)]==m:
		if bo:
			if y==a:
				l+=1
				y=b
			else:
				s+=(l*(l-1))//2
				l=2
				x=a
				y=b
		else:
			x,y=a,b
			bo=True
		
	a=b
if bo:
				s+=(l*(l-1))//2
print(n+s)
				
				
			
		
		
		