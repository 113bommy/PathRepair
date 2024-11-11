def check(n, d, x, y):
    ch = True
    if y < -x - d:
        ch = False
    if y < x - d:
        ch = False
    if y > x + d:
        ch = False
    if y > -x + 2 * n - d:
        ch = False
    return ch


n, d = map(int, input().split())
m = int(input())

for i in range(m):
    x, y = map(int, input().split())
    if check(n, d, x, y):
        print("YES")
    else:
        print("NO")