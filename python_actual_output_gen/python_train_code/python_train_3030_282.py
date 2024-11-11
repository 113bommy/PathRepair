n = int(input())
ans=0
for i in range(5,1,-1):
	ans+=(n//i)
	n=n%i
print(ans)