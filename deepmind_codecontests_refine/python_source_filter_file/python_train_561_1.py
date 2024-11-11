def bfs(x,y):
    p=0

    queue=[(x,y)]
    visited[x][y]=1


    while queue:
        a=queue.pop(0)
        p+=1

        #print(p,y-k)
        if p>=yh-k:
            t[a[0]][a[1]]='X'
            

        a0=a[0]
        a1=a[1]

        if a0+1<n and t[a0+1][a1]!='#' and visited[a0+1][a1]==0:
            queue.append((a0+1,a1))
            visited[a0+1][a1]=1
            
        if a0-1>=0 and t[a0-1][a1]!='#' and visited[a0-1][a1]==0:
            queue.append((a0-1,a1))
            visited[a0-1][a1]=1

        if a1+1<m and t[a0][a1+1]!='#' and visited[a0][a1+1]==0:
            queue.append((a0,a1+1))
            visited[a0][a1+1]=1

        if a1-1>=0 and t[a0][a1-1]!='#' and visited[a0][a1-1]==0:
            queue.append((a0,a1-1))
            visited[a0][a1-1]=1


        

n,m ,k =  map(int,input().split())

t=[]
yh=0


for i in range(n):
    s=list(input())
    t.append(s)

    yh+=s.count('.')
    if '.' in s:
        p=(i,s.index('.'))




visited=[[0 for i in range(m)] for j in range(n)]


bfs(p[0],p[1])


for j in t:
    print(''.join(j))
