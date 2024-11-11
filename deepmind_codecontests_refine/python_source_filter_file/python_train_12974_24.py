n,t=map(int,input().split())
a=list(map(int,input().split()))
sum=0
for i in range(n):
	sum+=(86400-a[i])
	if sum>=t:
		print(i+1)