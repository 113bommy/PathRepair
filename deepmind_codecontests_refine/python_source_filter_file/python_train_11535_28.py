import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

h,w = map(int, input().split())
a = [list(map(int, input().split())) for i in range(h)]
b = [list(map(int, input().split())) for i in range(h)]
ma = 3000
DP = [[[0]*ma for i in range(w)] for i in range(h)]

for i in range(h):
    for j in range(w):
        k = abs(a[i][j]-b[i][j])
        if i==0 and j==0:
            DP[i][j][k] = 1
            continue
        else:
            up = min((i+j+1)*80+1, ma-k)
            for l in range(up):
                DP[i][j][l] = DP[i][j-1][abs(l-k)] | DP[i][j-1][l+k] | DP[i-1][j][abs(l-k)] | DP[i-1][j][l+k]
for i in range(ma):
    if DP[-1][-1][i]:
        print(i)
        exit()
