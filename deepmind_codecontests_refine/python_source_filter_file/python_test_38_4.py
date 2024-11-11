import io,os
from collections import deque 

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def visit(nums,i,j,grid,m,n,flag):

    direc = [[0,1],[1,0]]
    queue = deque()
    queue.append([i,j])

    if flag:  nums[i][j] = j
    else: nums[i][j] = 0

    while queue:
#        print(queue)
        curri,currj = queue.popleft()
        
        for d in range(2):
            newi = curri + direc[d][0]
            newj = currj + direc[d][1]
            if newi<0 or newi>=m or newj<0  or newj>=n: continue
            if nums[newi][newj] >= 0: continue  

            if flag:  nums[newi][newj] = j
            else:  nums[newi][newj] = 0


            if grid[newi][newj]==ord('.'):
                queue.append([newi,newj])

    






def main(t):


    m,n = map(int,input().split())
    grid = []
    nums = [[-1 for j in range(n)] for i in range(m)]
    for i in range(m):
        grid.append( input() )

    maxnum = [-1]*n
    currmax = [-1]*n


    for j in range(n):
        if grid[0][j]==ord('.'):   
            visit(nums,0,j,grid,m,n,False)

#    print(nums)

    for j in range(n):
        for i in range(m):
            if nums[i][j]==-1:
                if grid[i][j]==ord('.'):
                    visit(nums,i,j,grid,m,n,True)
                elif grid[i][j]==ord('X'): 
                    nums[i][j] = j



        for i in range(m):
            maxnum[j] = max(maxnum[j],nums[i][j])

    
    currmax[0] = maxnum[0]
    for j in range(1,n):
        currmax[j] = max(currmax[j-1],maxnum[j])


#    print(nums)
#    print(maxnum)
#    print(currmax)
       

    q = int(input())
    for _ in range(q):
        front,rear = map(int,input().split())
        front -= 1
        rear -= 1
        if currmax[rear]>front:
            print("NO") 
        else:
            print("YES")
            
          

    


        

























T = 1 #int(input())
t = 1
while t<=T:
    main(t)
    t += 1
