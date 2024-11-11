n=int(input())
ans=[]

def dfs(i,c,d):
	if i==n:
		ans.append(c)
		return
	for j in range(0,d+1):
		dfs(i+1,c+chr(97+j),d+(i==d))

dfs(0,"",0)

print("\n".join(ans))