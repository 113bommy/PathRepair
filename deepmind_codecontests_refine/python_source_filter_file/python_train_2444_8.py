import sys
sys.setrecursionlimit(10000)

def dfs(x,y,startx,starty,color):
	global visited, board, cycled, numrows, numcols
	xmovement = [1,-1,0,0]
	ymovement = [0,0,1,-1]
	print('x is:',x,' ','y is:',y)
	print('Cycled is: ',cycled)
	if (x < 0 or x >= numrows or y < 0 or y >= numcols): #if not in range loop out
		#print('check fail')
		return cycled
	if (board[x][y] != color): #if not the same color loop out
		#print('color fail')
		return cycled
	if (cycled == True):
		#print('true already')
		return cycled
	if (visited[x][y]):
		cycled = True
		#print('cycled set')
		return cycled

	visited[x][y] = True
	for i in range(4):
		nextx = x + xmovement[i]
		nexty = y + ymovement[i]

		if ((nextx == startx) and (nexty == starty)):
			continue
		dfs(nextx,nexty,x,y,color)

lines = input().split(' ')
numrows= int(lines[0])
numcols = int(lines[1])

cycled = False
#create visited matrix - start with false
#[[0 for x in range(numcols)] for x in range(numrows)]
visited = [[False for x in range (numcols)] for x in range(numrows)]

#initialize board of colors
colors = []
board = []
for z in range(numrows):
	colors.append(input())
	board.append(list(colors[z]))

for succX in range(numrows):
    for succY in range(numcols):
        if not visited[succX][succY]:
            dfs(succX, succY, -1, -1, board[succX][succY])

if (cycled): 
	print('Yes')
else: 
	print('No')