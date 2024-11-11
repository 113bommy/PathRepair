n=int(input())
p=list(map(int,input().split()))
for i in range(n):
	if p[i]%2==0:
		p[i]=p[i]-1
print(*p)		