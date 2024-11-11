import sys
import queue

H,W = map(int,input().split())
white = 0
maze = [['#']*(W+2)]
for y in range(H):
	li = list(input())
	white += li.count('.')
	maze.append(['#'] + li + ['#'])
maze.append(['#']*(W+2))



def check(x,y,n):
	if 1 <= x < W+1 and 1 <= y < H+1:
		if x == W-1 and y == H-1:
			print (white - n - 1)
			sys.exit()
		elif maze[y][x] == '.':
			maze[y][x] = n
			q.put([x-1,y,n+1])
			q.put([x+1,y,n+1])
			q.put([x,y-1,n+1])
			q.put([x,y+1,n+1])
		else:
			return
	else:
		return

q = queue.Queue()
q.put([1,1,0])
while not q.empty():
	x,y,n = q.get()
	check(x,y,n)

print(-1)
