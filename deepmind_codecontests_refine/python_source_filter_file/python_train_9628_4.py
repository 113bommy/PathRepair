n, k = map(int, input().split())
map = []
for i in range(n):
    map.append(['S' for j in range(n)])
if k >= n * n:
    print("NO")
    exit()
for i in range(n):
    if k == 0:
        break
    for j in range(n):
        if k == 0:
            break
        if j - 1 >= 0 and map[i][j - 1] == 'L':
            continue
        if i - 1 >= 0 and map[i - 1][j] == 'L':
            continue
        map[i][j] = 'L'
        k -= 1
if k == 0:
    print("YES")
    print('\n'.join(''.join(i) for i in map))
else:
    print("NO")
