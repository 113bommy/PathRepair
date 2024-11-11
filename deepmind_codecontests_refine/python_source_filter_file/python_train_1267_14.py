n, x, y = map(int, input().split())
sp = list(map(int, input().split()))
for i in range(0, n):
    k = 0
    sx = 0
    d = 0
    j1 = 0
    j2 = 0
    min1 = 10000000000000000
    if i < x:
        j1 = 0
    else:
        j1 = i - x
    if i > n - y:
        j2 = n
    else:
        j2 = i + y
    for j in range(j1, i):
        min1 = min(min1, sp[j])
#    print(min1)
    if sp[i] >= min1:
        continue
    min1 = sp[i]
    for j in range(i + 1, j2):
        if min1 >= sp[j]:
            d = 1
            break
    if d == 0:
        print(i + 1)
        break



