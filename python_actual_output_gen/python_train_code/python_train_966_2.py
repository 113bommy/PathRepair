input()

def p(x):
    x = int(x) - 1
    if x == -1:
        return (3, 1)
    return (x // 3, x % 3)

s = list(map(p, input()))
f = False
for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
    f = f or not [1 for i, j in s if i + di < 0 or i + di >= 3 or j + dj < 0 or j + dj >= 4 or j + dj == 3 and i + di != 1]
print("NO" if f else "YES")
