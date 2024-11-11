N,K = map(int,input().split())

grid = [[0]*(2*K+2) for i in range(2*K+2)]
for i in range(N):
    x,y,c = input().split()
    x,y = int(x),int(y)
    if c == 'W':
        x += K
    grid[y%(2*K)+1][x%(2*K)+1] += 1

for i in range(2*K+2):
    for j in range(2*K+1):
        grid[i][j+1] += grid[i][j]
for i in range(2*K+1):
    for j in range(2*K+2):
        grid[i+1][j] += grid[i][j]

def count(x1,x2,y1,y2):
    return grid[y1][x1] - grid[y1][x2] - grid[y2][x1] + grid[y2][x2]

ans = 0
for i in range(K):
    for j in range(K):
        tmp = count(j,j+K,i,i+K) + count(0,j,0,i) + count(j+K,2*K,0,i) +\
            count(0,j,i+K,2*K) + count(j+K,2*K,i+K,2*K)
        ans = max(ans, tmp)
print(ans)