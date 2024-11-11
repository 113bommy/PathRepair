n,m=map(int, input().split())
ans=[0]*n
for i in range(m):
	ls=list(map(int, input().split()))
	ans[ls.index(max(ls))] +=1
print(ans.index(max(ans))+1)
