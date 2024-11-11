n,k,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
ans=sum(a)/n
cm=[a[0]]
for i in range(1,n):
	cm.append(cm[-1]+a[i])
cm.append(0)
for d in range(n):
	nb=min((m-d)//k,n-d)
	r=(m-d)%k if nb<n-d else 0
	ans=max(ans,(cm[-2]-cm[d-1]+nb*k+r)/(n-d))
print(ans)