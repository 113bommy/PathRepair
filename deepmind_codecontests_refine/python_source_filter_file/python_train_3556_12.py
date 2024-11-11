import sys
f = sys.stdin
# f = open("input.txt", "r")
n, m = map(int, f.readline().strip().split())
a = f.read().strip().split("\n")
w = [[0]*m for i in range(n)]
p = [[0]*m for i in range(n)]
def wolves():
    for row in range(n):
        for col in range(m):
            if a[row][col] == "W":
                cnt = 0
                if col < m-1:
                    if a[row][col+1] == "P":
                        cnt += 1
                if col >= 1:
                    if a[row][col-1] == "P":
                        cnt += 1
                if row < n-1:
                    if a[row+1][col] == "P":
                        cnt += 1
                if row >= 1:
                    if a[row-1][col] == "P":
                        cnt += 1
                w[row][col] = cnt
def pigs():
    for row in range(n):
        for col in range(m):
            if a[row][col] == "P":
                cnt = 0
                if col < m-1:
                    if a[row][col+1] == "W":
                        cnt += 1
                if col >= 1:
                    if a[row][col-1] == "W":
                        cnt += 1
                if row < n-1:
                    if a[row+1][col] == "W":
                        cnt += 1
                if row >= 1:
                    if a[row-1][col] == "W":
                        cnt += 1
                p[row][col] = cnt
wolves()
pigs()
def stat():
    for i in zip(w,p):
        print(*i)
    print()
# stat()
res = 0
for i in range(n):
    for j in range(m):
        if p[i][j]:
            p[i][j] = 0
            mn = 99999999
            x, y = -1, -1
            if j < m-1:
                if 0 < w[i][j+1] < mn:
                    mn = w[i][j+1]
                    x, y = i, j+1
            if j >= 1:
                if 0 < w[i][j-1] < mn:
                    mn = w[i][j-1]
                    x, y = i, j-1
            if i < n-1:
                if 0 < w[i+1][j] < mn:
                    mn = w[i+1][j]
                    x, y = i+1, j
            if i >= 1:
                if 0 < w[i-1][j] < mn:
                    mn = w[i-1][j]
                    x, y = i-1, j
            print("x:", x, "y:", y)
            if x != -1 and y != -1:
                w[x][y] = 0
                res += 1
            # stat()
# stat()
print(res)