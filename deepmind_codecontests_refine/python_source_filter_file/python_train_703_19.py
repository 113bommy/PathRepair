n, m = map(int, input().split())
sc = [list(map(int, input().split()))for i in range(m)]

ans = -1
for i in range(1, 1000):
    if len(str(i)) != n:
        continue
    for s, c in sc:
        if str(i)[s-1] != str(c):
            break
    else:
        ans = i
        break
print(ans)
