import sys
sys.setrecursionlimit(160000)

H,W = map(int,input().split(' '))
S = []
for i in [0]*H:
	l = input()
	S.append([1 if x == '#' else -1 for x in l])

bk = 0
wh = 0
def check(S,x,y):
	global bk
	global wh
	if S[y][x] == 0:
		return
	if S[y][x] == 1:
		bk += 1
		S[y][x]=0
		if 0 < y and S[y-1][x] == -1:
			check(S,x,y-1)
		if 0 < x and S[y][x-1] == -1:
			check(S,x-1,y)
		if y < H-1 and S[y+1][x] == -1:
			check(S,x,y+1)
		if x < W-1 and S[y][x+1] == -1:
			check(S,x+1,y)
		return
	if S[y][x] == -1:
		wh += 1
		S[y][x]=0
		if 0 < y and S[y-1][x] == 1:
			check(S,x,y-1)
		if 0 < x and S[y][x-1] == 1:
			check(S,x-1,y)
		if y < H-1 and S[y+1][x] == 1:
			check(S,x,y+1)
		if x < W-1 and S[y][x+1] == 1:
			check(S,x+1,y)
		return

cnt = 0
for y in range(H):
	for x in range(W):
		if S[y][x] == 1:
			check(S,x,y)
			cnt += wh*bk
			wh = 0
			bk = 0
print(cnt)


