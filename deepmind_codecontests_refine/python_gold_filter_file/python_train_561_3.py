maze = [['0' for j in range(510)] for i in range(510)]
visited = [[0 for j in range(510)] for i in range(510)]
n,m,k = tuple(int(i) for i in input().split())
sx = -1
sy = -1
for i in range(n):
	s = input()
	for j in range(m):
		maze[i][j] = s[j]
		if(sx==-1 and s[j]=='.'):
			sx=i
			sy=j


stack = [(sx,sy)]
ans = []
while(len(stack)!=0):
	curr = stack.pop()
	x = curr[0]
	y = curr[1]
	#print(x,y)
	if(x<0 or y<0 or x>=n or y>=m or visited[x][y]==1 or maze[x][y]=='#'):
		continue
	visited[x][y] = 1
	stack.append((x+1,y))
	stack.append((x-1,y))
	stack.append((x,y+1))
	stack.append((x,y-1))
	ans.append(curr)

for i in range(k):
	curr = ans[len(ans)-i-1]
	x = curr[0]
	y = curr[1]
	maze[x][y] = 'X'
s = ""
for i in range(n):
	for j in range(m):
		s+=maze[i][j]
	s+="\n"
print(s)
