l, r, x, y, k = map(int, input().split())
for J in range(l, r + 1):
    if y >= k * J >= x:
        print('YES')
        exit(0)
print('NO')