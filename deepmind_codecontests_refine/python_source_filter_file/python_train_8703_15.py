l, r, x, y, k = map(int, input().split())
for i in range(l, r + 1):
    if x <= i * k <= y:
        print("YES")
        exit()
print("NO")
