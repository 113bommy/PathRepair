a,b,c=map(int,input().split())
ans=0
for i in range(1,b+1):
	a=a*10
	ans=ans+1
	if a//b==c:
		print(ans)
		exit()
	a=a%b
print(-1)
