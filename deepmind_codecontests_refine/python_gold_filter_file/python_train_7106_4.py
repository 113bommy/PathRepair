n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
for pw in range(9, -1, -1):
    x = 2 ** pw
    p = []
    for i in range(n):
        if a[i] & x > 0:
            p.append(a[i])
    if len(p) == 0:
        continue
    #print(x)
    for j in range(m):
        if b[j] & x != 0:
            continue
        ok = False
        for ai in p:
            if ((ai & b[j]) | ans) - ans > x:
                break
        else:
            break
    else:
        ans += x
print(ans)
