n=int(input())
a=[0]*n
for _ in range(n):
	a[int(input())-1]=_

k=1
ans=1
for i in range(n-1):
	if a[i]<a[i+1]:
		k+=1
	else:
		ans=max(ans,k)
		k=1
print(n-ans)
