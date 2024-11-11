n,k=map(int,input().split())


def f(x,d):
    a = x-d+1
    if a < 1:
        return 0
    return a

def g(l,r,d):
    a = f(l+r,d)
    if a == 0:
        return 0
    return a-f(l-1,d)-f(r-1,d)
    
        
grid = []
for i in range(n):
    grid.append(input())

M = 0
ans = [0,0]
for row in range(n):
    for col in range(n):
        if grid[row][col] == '.':
            i = col
            while i>0 and grid[row][i] == '.':
                i -= 1
            l = col-i-1
            
            j = col
            while j<n-1 and grid[row][j] == '.':
                j += 1
            r = j-col-1

            
            i = row
            while i>0 and grid[i][col] == '.':
                i -= 1
            u = row-i-1
    
            j = row
            while j<n-1 and grid[j][col] == '.':
                j += 1
            d = j-row-1
            
            if g(l,r,k-1)+g(u,d,k-1) > M:
                M = g(l,r,k-1)+g(u,d,k-1)
                ans = [row,col]

print(ans[0]+1, ans[1]+1)
            

