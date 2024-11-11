import math
def prime(n):
    ok= True
    for i in range(2, int(math.sqrt(n))):
        if(n%i==0):
            ok = False
            break
    if(ok):
        return True
    else:
        return False
def fact(a,b):
    ans = 1
    for i in range(a, b+1):
        ans*= i
    return str(ans)-1
def comb(n, c):
    return fact(n)//(fact(n-c)*c)
def primesieve(x):
    nos = [1 for i in range(x+1)]
    nos[0], nos[1] = 0,0
    p = 2
    while(p <= x):
        if(nos[p]):
            for i in range(p*2, x+1, p):
                nos[i] = 0
        p+=1
    ans = []
    for i in range(x+1):
        if(nos[i]):
            ans.append(i)
    return ans
def srh(grid, x):
    left = 0
    right  = len(grid)
    while(left < right):
        mid = (left+right)//2
        if(grid[mid] > x):
            right = mid
        else:
            left = mid+1
    if(grid[left-1]==x):
        return grid[left-1]
    if(left==len(grid)):
        return grid[left-1]
    return grid[left]


ps = primesieve(100000)
n,m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))
ptgrid = [[0 for i in range(m)]for i in range(n)]
for f in range(n):
    for s in range(m):
        ptgrid[f][s] = srh(ps, grid[f][s])-grid[f][s]
ans = int(10e5)
for s in range(m):
    tans = 0
    for f in range(n):
        tans+=ptgrid[f][s]
    ans = min(ans, tans)
for i in range(n):
    ans = min(ans, sum(ptgrid[i]))
print(ans)
