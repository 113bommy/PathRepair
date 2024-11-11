import sys
input = sys.stdin.readline

N,M=map(int,input().split())
MAP=[list(input().strip()) for i in range(N)]

start=N*M+2
goal=N*M+3

EDGE=[set() for i in range(N*M+5)]

for i in range(N):
    for j in range(M):
        if (i+j)%2==0 and MAP[i][j]==".":
            EDGE[start].add(i*M+j)

            for x,y in [(i+1,j),(i-1,j),(i,j+1),(i,j-1)]:
                if 0<=x<N and 0<=y<M and MAP[x][y]==".":
                    EDGE[i*M+j].add(x*M+y)

        if (i+j)%2==1 and MAP[i][j]==".":
            EDGE[i*M+j].add(goal)

count=0 # カット数をカウント

while True:

    USED=[0]*(N*M+5)
    ROUTE=[-1]*(N*M+5)
    Q=[start]
    
    while Q: # 探索
        NOW=Q.pop()
        if NOW==goal:
            break
        
        for to in EDGE[NOW]:
            if USED[to]==0:
                ROUTE[to]=NOW # EDGEの更新用に後ろから辿る方法を覚えておく
                USED[to]=1
                Q.append(to)
    else:
        break

    count+=1
    i=goal
    while i!=start: # goalからたどり,Routeを使ってEDGEの更新
        j=ROUTE[i]
        EDGE[j].remove(i) # 使ったルートをいけなく更新
        EDGE[i].add(j) # 逆向きに進めるようにする.これらを重みつきにすれ普通のフロー
        i=j
        
print(count)

for i in range(N):
    for j in range(M):
        if (i+j)%2==1:
            for to in EDGE[i*M+j]:
                if M>1 and to == i*M+j-1:
                    MAP[i][j]="<"
                    MAP[i][j-1]=">"
                elif M>1 and to == i*M+j+1:
                    MAP[i][j]=">"
                    MAP[i][j+1]="<"
                elif to == i*M+j-M:
                    MAP[i][j]="^"
                    MAP[i-1][j]="v"
                elif to == i*M+j+M:
                    MAP[i][j]="v"
                    MAP[i+1][j]="^"

for m in MAP:
    print("".join(m))
                    
