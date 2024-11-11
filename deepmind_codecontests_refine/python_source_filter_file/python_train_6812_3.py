a,b,k = map(int, input().split())
k += 1
m = [[ord(c)-48 for c in input()] for i in range(a)][-1::-1]
dp = [[[-1 for t in range(k)] for j in range(b)] for i in range(a)]
pr = [[[0 for t in range(k)] for j in range(b)] for i in range(a)]
for i in range(a):
    for j in range(b):
        if i==0:
            dp[i][j][m[i][j]%k] = m[i][j]
            continue
        for c in range(k):
            l = dp[i-1][j-1][(c-m[i][j])%k]+m[i][j] if j and dp[i-1][j-1][(c-m[i][j])%k]>-1 else 0
            r = dp[i-1][j+1][(c-m[i][j])%k]+m[i][j] if j+1<b and dp[i-1][j+1][(c-m[i][j])%k]>-1 else 0
            dp[i][j][c] = max(l,r)
            pr[i][j][c] = -1 if l>r else 1
mx = 0
ep = -1
for j in range(b):
    if dp[a-1][j][0]<=mx: continue
    mx = dp[a-1][j][0]
    ep = j
if mx==0:
    print(-1)
    exit(0)
print(mx)
path = ""
x, y = a-1, ep
while 1:
    if x==0: break
    path += "R" if pr[x][y][mx%k]==-1 else 'L'
    c = mx
    mx -= m[x][y]
    y += -1 if pr[x][y][c%k]==-1 else 1
    x -= 1
print(y+1)
print(path[-1::-1])
