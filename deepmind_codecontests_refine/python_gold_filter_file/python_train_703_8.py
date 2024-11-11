n, m = map(int, input().split())

sc = [[int(x) for x in input().split()] for _ in range(m)]
ans = -1
for i in range(10**n):
    if len(str(i)) != n:
        continue
    x = str(i)
    for s, c in sc:
        if int(x[s-1]) != c:
            break
    else:
        print(i)
        exit()
print(-1)   