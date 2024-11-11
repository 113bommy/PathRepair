n=int(input())
a=list(map(int,input().split()))
if n%2==0:
	m=int(n/2)
else:
	m=n//2+1	
s=0
k=0
print(m)
for i in range(n):
	if a[i]>0:
		s+=1
	elif a[i]<0:
		k+=1
if s>=m:
	print(4)
elif k>=m:
	print(-1)
else:
	print(0)