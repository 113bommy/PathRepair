n,k = map(int,input().split())
pn = list(map(int,input().split()))
cn = list(map(int,input().split()))
ans = -float("inf")


for i in range(n): 
    start=i
    now=start
    total = 0 #ループ計
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
        continue  #roopなし

    if total <= 0:
        continue
    else:
        if k % rp == 0:
            ans2 = total * (k // rp-1) + max(ls)
            ans = max(ans, ans2)
        else:
            ans2 = total * (k//rp) + max(ls[:k%rp+1])
            ans = max(ans, ans2)
print(ans)
