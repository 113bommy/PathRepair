l, r, x, y, k = map(int, input().split())
for i in range(x, y + 1):
    if l <= i * k <= r:
        print("YES")
        exit()
print("NO")
