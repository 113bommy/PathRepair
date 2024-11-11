w,l=map(int,input().split())
a=list(map(int,input().split()))
s,mn=0,100000000
for i in range(l):s+=a[i]
mn=min(mn,s)
for i in range(l,w-1):
	s+=a[i];s-=a[i-l]
	mn=min(mn,s)
print(mn)
	
