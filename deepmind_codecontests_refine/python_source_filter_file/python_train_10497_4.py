import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")



n,k = list(map(int, input().split()))
v = [[0]*(2*k) for _ in range(2*k)]

for i in range(n):
    x,y,c = input().split()
    x = int(x)
    y = int(y)
    if c=="B":
        x += k
    x %= 2*k
    y %= 2*k
    v[x][y] += 1
#     v[x][y+2*k] += 1
#     v[x+2*k][y] += 1
#     v[x+2*k][y+2*k] += 1
def cumsum2(v):
    # v: h*wの2次元リスト
    h,w = len(v), len(v[0])
    v.insert(0, [0]*w)
    for l in v:
        l.insert(0, 0)
    for i in range(1,h+1):
        for j in range(1,w+1):
            v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1] + v[i][j]
    return v
cumsum2(v)

def sub(c, i, j):
    i %= 2*k
    j %= 2*k
    l = []
    if i<=k and j<=k:
        l = [[i,i+k,j,j+k]]
    elif i>k and j<=k:
        l = [[i,2*k,j,j+k], [0,i-k,j,j+k]]
    elif i<=k and j>k:
        l = [[i,i+k,j,2*k], [i,i+k,0,j-k]]
    else:
        l = [[i,2*k,j,2*k], [0,i-k,j,2*k], [i,2*k,0,j-k], [0,i-k,0,j-k]]
    return sum((c[z][w] - c[z][y] - c[x][w] + c[x][y]) for x,z,y,w in l)
ans = -1
for i in range(2*k):
    for j in range(2*k):
        val0 = sub(v, i,j) + sub(v, i+k, j+k)
#         val0 = v[i+k][j+k]-v[i+k][j]-v[i][j+k]+v[i][j] + v[i+2*k][j+2*k]-v[i+2*k][j+k]-v[i+k][j+2*k]+v[i+k][j+k]
#         val1 = v[i+2*k][j+k]-v[i+2*k][j]-v[i+k][j+k]+v[i+k][j] + v[i+k][j+2*k]-v[i+k][j+k]-v[i][j+2*k]+v[i][j+k]
        ans = max(ans, val0)
print(ans)