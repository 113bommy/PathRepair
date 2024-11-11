n,k=map(int,input().split())
p=list(map(int,input().split()))
c=list(map(int,input().split()))
ans=-10**10
for i in range(n):
	loop=[0]
	now=i
	while True:
		now=p[now]-1
		loop.append(loop[-1]+c[now])
		if now==i:
			break
	L=len(loop)-1
	if k<=L:
		score=max(loop[1:k+1])
		ans=max(score,ans)
	else:
		score=max(loop[-1],0)*(k//L-1)
		ans=max(ans,score)
		for j in range(k%L+L):
			score+=loop[j%L+1]-loop[j%L]
			ans=max(score,ans)
print(ans)