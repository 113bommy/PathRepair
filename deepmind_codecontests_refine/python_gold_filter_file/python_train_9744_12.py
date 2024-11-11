n,k=[int(i)for i in input().split()]
l=[int(i)for i in input().split()]
ans=0
if sum(l)/n<k-0.5:
	ans = int(((k-0.5)*n-sum(l))/0.5)

print(ans)	

