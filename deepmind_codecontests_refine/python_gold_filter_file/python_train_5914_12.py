n=int(input())
p=list(map(int,input().split()))
a=0
for i in range(1,n-1):
	a+=p[i]>min(p[i-1],p[i+1]) and p[i]<max(p[i-1],p[i+1])
print(a)