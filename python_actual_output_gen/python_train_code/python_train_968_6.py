n,m=map(int,input().split())
a=min(n,m)
for i in range(2,a+1):
	n*=i
print(n)