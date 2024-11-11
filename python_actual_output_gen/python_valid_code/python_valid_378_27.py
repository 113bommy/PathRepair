n=int(input())
ans=10**9
for i in range(1,int(n**(1/2))+1):
	if n%i==0:
		ans=min(ans,i+n//i-2)
print(ans)