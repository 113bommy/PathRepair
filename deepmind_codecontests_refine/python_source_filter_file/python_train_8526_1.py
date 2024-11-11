import sys
sys.setrecursionlimit(1<<32)
def f(x,y):
    a[y][x]='0'
    for dx,dy in[[-1,0],[1,0],[0,-1],[0,1],[-1,-1],[1,-1],[-1,1],[1,1]]:
        dx+=x;dy+=y
        if 0<=dx<w and 0<=dy<h and a[dy][dx]=='1':f(dx,dy)
while 1:
    w,h=map(int,input().split())
    if w==0:break
    a=[list(input().split()) for _ in[0]*h];b=0
    for i in range(w):
        for j in range(h):
            if a[j][i]=='1':
                b+=1;f(i,j)
    print(b)