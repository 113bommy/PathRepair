N=int(input())
a=list(map(int,input().split()))
a.sort()
for i in(1,N):
	a[0]=(a[0]+a[i])/2
print(a[0])