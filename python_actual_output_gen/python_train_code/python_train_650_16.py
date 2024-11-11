n,d=map(int,input().split())
for i in range(n):
	a,b=map(int,input().split())
	if a*a+b*b<=d*d:ans+=1
print(ans)