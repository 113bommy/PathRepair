from collections import deque
def bfs(i,j):
    q=deque([(i,j)])
    while q:
        i,j=q.popleft()
        for a,b,d in [(i+1,j,'U'),(i-1,j,'D'),(i,j+1,'L'),(i,j-1,'R')]:
            if a==-1 or a==n or b==-1 or b==n or v[a][b]:
                continue
            if m[a][b]==m[i][j]:
                v[a][b]=d
                q.append((a,b))
n=int(input())
m=[[None]*n for _ in range(n)]
v=[[False]*n for _ in range(n)]
for i in range(n):
    r=[int(i) for i in input().split()]
    for j in range(n):
        a,b=r[2*j]-1,r[2*j+1]-1
        m[i][j]=(a,b)
for i in range(n):
    for j in range(n):
        if m[i][j]==(i,j):
            v[i][j]="X"
            bfs(i,j)
        if m[i][j]==(-2,-2):
            for a,b,nxt,prev in [(i+1,j,'D','U'),(i-1,j,'U','D'),(i,j+1,'R','L'),(i,j-1,'L','R')]:
                if a==-1 or a==n or b==-1 or b==n:
                    continue
                if m[a][b]==(-2,-2):
                        v[i][j],v[a][b]=nxt,prev
                        break
            else:
                print("INALID")
                exit()
for i in range(n):
    for j in range(n):
        if v[i][j]==False:
            print("INVALID")
            exit()
print('VALID')
print('\n'.join([''.join(x) for x in v]))
                
