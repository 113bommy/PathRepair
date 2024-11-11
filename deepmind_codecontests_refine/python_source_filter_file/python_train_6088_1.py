#!/usr/bin/python3
# A. Reposts

def dfs(curpost):
	global adjlist, visited
	visited.add(curpost)
	count = 0
	if curpost in adjlist:
		for post in adjlist[curpost]:
			if post not in visited:
				val = dfs(post)
				if val > count:
					count = val
	return count + 1
	

n = int(input())
adjlist = {}
visited = set() 
for i in range(n):
	line = input().split()
	if line[2].lower not in adjlist:
		adjlist[line[2].lower()] = [line[0].lower()]
	else:
		adjlist[line[2].lower()].append(line[0].lower())

ans = dfs("polycarp")
print(ans)


