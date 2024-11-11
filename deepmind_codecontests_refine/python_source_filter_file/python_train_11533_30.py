from collections import deque
import sys
input=sys.stdin.readline
inf=float("inf")


def BFS():
    D=[[inf for _ in range(w)] for _ in range(h)]
    queue=deque()
    queue.append([Cx-1,Cy-1,0])
    D[Cx-1][Cy-1]=0

    while len(queue)>0:
        x,y,cnt=queue.popleft()
        for i,j in [[1,0],[0,1],[-1,0],[0,-1]]:
            X,Y=x+i,y+j
            if 0<=X<h and 0<=Y<w:
                if S[X][Y]=="." and D[X][Y]>cnt:
                    D[X][Y]=cnt
                    queue.append([X,Y,cnt])

        for X in range(max(0,x-2),min(h,x+3)):
            for Y in range(max(0,y-2),min(w,y+3)):
                if S[X][Y]=="." and D[X][Y]>cnt+1:
                    D[X][Y]=cnt+1
                    queue.append([X,Y,cnt+1])

    return D[Dx-1][Dy-1]


h,w=map(int,input().split())
Cx,Cy=map(int,input().split())
Dx,Dy=map(int,input().split())
S=[list(input()) for _ in range(h)]

D=BFS()
print(D if D!=inf else -1)