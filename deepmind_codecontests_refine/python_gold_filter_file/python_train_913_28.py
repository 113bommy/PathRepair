N=int(input())
a=list(map(int,input().split()))
a.sort()
for i in a:
	a[0]=(a[0]+i)/2
print(a[0])