N=int(input())
n=round(N**(1/2))
for i in range(1,n+2):
	if N/i==N//i:
		ans=i+N/i-2
print(ans)