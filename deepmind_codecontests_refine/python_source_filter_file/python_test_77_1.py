from collections import deque 
import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


grid = []
m, n = map(int,input().split())

visited = [[False for j in range(n)] for i in range(m)]


for i in range(m):
    for j in range(n):
        grid.append( list(map(int,input().split())) )

direc = [[0,-1],[1,0],[0,1],[-1,0]]


#  calculate the area of room contains (i,j)
def get_dimension(i,j):

    queue = deque()
    output = 0
    queue.append([i,j])
    visited[i][j] = True


    while queue:
        [curri,currj] = queue.popleft()
        output += 1
        for d in range(4):
           
            if grid[curri][currj] & (1<<d) > 0: continue 

            newi = curri + direc[d][0]
            newj = currj + direc[d][1]
            if newi<0 or newi>=m or newj<0 or newj>=n: continue 
            if visited[newi][newj]: continue 
            if grid[newi][newj] & (1<<((d+2)%4)): continue 
            visited[newi][newj] = True
            queue.append([newi,newj])

    return output 





    




ans = []


for i in range(m):
    for j in range(n):
        if visited[i][j]:  continue 
        
        ans.append( get_dimension(i,j) ) 

ans = sorted(ans,reverse=True)

print(" ".join(map(str,ans)))


        
                
        



















