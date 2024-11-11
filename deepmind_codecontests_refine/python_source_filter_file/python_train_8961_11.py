

from collections import defaultdict
#start the code from here
# no of egdes..


# simple DFS EDITED VERSION......
def dfs(stack,visited,g):

	while stack:
		# print(stack,visited)
		p=stack.pop()
		if visited[p]!=2:
			visited[p]+=1
			if visited[p]==2:
				# print(p+1,"pp")
				return p+1
				# print("yes")
		for i in g[p]:
			# print(i,"kya dikkat h")
			if visited[i]!=2:
				stack.append(i)
		# print(stack)


t=int(input())

g=defaultdict(list)
l=list(map(int,input().split()))
for i in range(t):
	a,b=i+1,l[i]
	a=a-1
	b=b-1
	g[a].append(b)
print(g)
ans=[]
for i in range(t):
	visited=[0]*t
	stack=[i]
	ans.append(dfs(stack,visited,g))
print(*ans)