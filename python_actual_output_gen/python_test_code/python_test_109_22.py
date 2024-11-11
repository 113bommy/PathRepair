n=int(input())
L=list(map(int,input().split()))
ans=1
for i in range(n):
	ans=ans*L[i]
	if ans>pow(10,18):
		print(-1)
		exit()
print(ans)