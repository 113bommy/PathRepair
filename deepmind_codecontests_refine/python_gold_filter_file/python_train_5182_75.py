n, k = map(int, input().split())
pn = list(map(int, input().split()))
cn = list(map(int, input().split()))

ans = -float('inf')

for i in range(n): #start
    start = i
    now = start
    total = 0
    ls = [0]

    for j in range(1, k+1):
        now = pn[now]-1
        total += cn[now]
        ans = max(ans, total)
        ls.append(total)
        if now == start:
            rp = j
            break
    else:
        continue

    if total <= 0:
        continue
    else:
        if k % rp == 0:
            s = k % rp
            ans2 = total * (k // rp-1) + max(ls)
            ans = max(ans, ans2)
        else:
            s = k % rp
            ans2 = total * (k//rp) + max(ls[:s+1])
            ans = max(ans, ans2)
print(ans)