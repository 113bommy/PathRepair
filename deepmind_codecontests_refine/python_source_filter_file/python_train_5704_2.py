h,w = map(int,input().split())
map1 = [list(input()) for _ in range(h)]
check_board = [[300]*w for _ in range(h)]
for x in range(h):
	for y in range(w):
		map1[x][y] = 1 if map1[x][y] =="#" else 0
check_board[0][0] = map1[0][0]
def cal_ans(a,b,x,y):
	return ((map1[a][b]^map1[x][y])&map1[x][y])+check_board[x][y]
for x in range(h):
	for y in range(w):
		if x < h-1:
			check_board[x+1][y] = min(check_board[x+1][y],cal_ans(x+1,y,x,y))
		if y < w-1:
			check_board[x][y+1] = min(check_board[x][y+1],cal_ans(x,y+1,x,y))
print(check_board[-1][-1])
