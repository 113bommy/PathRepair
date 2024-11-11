import sys
input=sys.stdin.readline
h,w=map(int,input().split())
red=[list(map(int,input().split()))+[0] for i in range(h)]+[[0 for i in range(w+1)]]
blue=[list(map(int,input().split()))+[0] for i in range(h)]+[[0 for i in range(w+1)]]
field=[[[0 for h in range(6401)] for i in range(w+1)] for j in range(h+1)]
field[0][0][abs(red[0][0]-blue[0][0])]=1
for i in range(h):
    for j in range(w):
        for f in range(6401):
            if field[i][j][f]==1:
                field[i][j+1][f+abs(red[i][j+1]-blue[i][j+1])]=1
                field[i][j+1][abs(f-abs(red[i][j+1]-blue[i][j+1]))]=1
                field[i+1][j][f+abs(red[i+1][j]-blue[i+1][j])]=1
                field[i+1][j][abs(f-abs(red[i+1][j]-blue[i+1][j]))]=1
for i in range(6401):
    if field[h-1][w-1][i]==1:print(i);exit()
