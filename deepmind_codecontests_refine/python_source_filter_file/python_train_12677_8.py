n,m,k=map(int,input().split())

a=list(map(int,input().split()))
b=list(map(int,input().split()))


a_pre,b_pre=[0],[0]

for i in range(n):
	a_pre.append(a_pre[i]+a[i])

for i in range(m):
	b_pre.append(b_pre[i]+b[i])

ans,j=0,m
for i in range(n+1):
	if a_pre[i]>k:
		break
	while b[j]>k-a[i]:
		j-=1

	ans=max(ans,i+j)

print(ans)
