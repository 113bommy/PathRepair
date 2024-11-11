n,m,k,x,y = map(int,input().split());
allnum = 0;
allnum = 2*n*m - 2*m
if n <= 2:
    allnum = 2*n*m;
num =  2*(k // allnum);
r = k%(allnum);
g = [ [num]* m for i in range(0, n)]
if n > 2:
    g[0] = [num //2]*m;
    g[n-1] = [num //2]*m;
for i in range(0, n):
    for j in range(0, m):
        if r == 0:
            break;
        g[i][j]+=1
        r-=1
    if r == 0:
        break;
for i in range(max(n - 2,0), -1,-1):
    for j in range(0, m):
        if r == 0:
            break;
        g[i][j]+=1
        r-=1
    if r == 0:
        break;
mn = num + 1000000000000000;
mx = 0
for i in range(0, n):
    if( max(g[i]) > mx):
        mx = max(g[i])
    if(min(g[i]) < mn):
        mn = min(g[i])

print(mx,mn,g[x-1][y-1]);
