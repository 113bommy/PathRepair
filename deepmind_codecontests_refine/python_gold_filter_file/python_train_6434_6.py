n, m = map(int, input().split())
x = 1
y = n
for i in range(m):
    l, r = map(int, input().split())
    x = max(l, x)
    y = min(r, y)
print(max(0, y-x+1))