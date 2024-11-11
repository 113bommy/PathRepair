import sys
sys.setrecursionlimit(10000)
def fill(y,x):
    global w,h,l
    if 0<=y<h and 0<=x+1<w and l[y][x+1]==1:
        l[y][x+1]=0
        fill(y,x+1)
    if 0<=y<h and 0<=x-1<w and l[y][x-1]==1:
        l[y][x-1]=0
        fill(y,x-1)
    if 0<=y+1<h and 0<=x<w and l[y+1][x]==1:
        l[y+1][x]=0
        fill(y+1,x)
    if 0<=y-1<h and 0<=x<w and l[y-1][x]==1:
        l[y-1][x]=0
        fill(y-1,x)
    
    if 0<=y+1<h and 0<=x+1<w and l[y+1][x+1]==1:
        l[y+1][x+1]=0
        fill(y+1,x+1)
    if 0<=y-1<h and 0<=x+1<w and l[y-1][x+1]==1:
        l[y-1][x+1]=0
        fill(y-1,x+1)
    if 0<=y+1<h and 0<=x-1<w and l[y+1][x-1]==1:
        l[y+1][x-1]=0
        fill(y+1,x-1)
    if 0<=y-1<h and 0<=x-1<w and l[y-1][x-1]==1:
        l[y-1][x-1]=0
        fill(y-1,x-1)
    
while 1:
    w,h=map(int,input().split())
    if not w and not h:break
    l=[list(map(int,input().split())) for _ in range(h)]

    cnt=0
    while 1:
        cds=[[i,j.index(1)] for (i,j) in enumerate(l) if 1 in j]
        if not cds:
            break
        else:
            y,x=cds[0]
        l[y][x]=0
        fill(y,x)
        cnt+=1
    print(cnt)
