import collections
H,W=map(int,input().split())
went=[[False]*W for i in range(H)]
queue=collections.deque()
for hoge in range(H):
    for huga,t in enumerate(input()):
        if t=="#":
            went[hoge][huga]=True
            queue.append([hoge,huga,0])
while queue:
    curx,cury,ct=queue.popleft()
    for dx,dy in [[1,0],[-1,0],[0,1],[0,-1]]:
        newx,newy=curx+dx,cury+dy
        newct=ct+1
        if 0<=newx<H and 0<=newy<W and (not went[newx][newy]):
            went[newx][newy]=True
            queue.append([newx,newy,newct])
print(ct)