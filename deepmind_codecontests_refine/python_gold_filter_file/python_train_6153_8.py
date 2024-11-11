n, d = map(int, input().split())

struct = {}

for i in range(n + 1):
    struct[i] = (i + d if i + d < n else n - (i + d) % n, abs(i - d))

m = int(input())

for i in range(m):
    x, y = map(int, input().split())
    if struct[x][1] <= y <= struct[x][0]:
        print("YES")
    else:
        print("NO")