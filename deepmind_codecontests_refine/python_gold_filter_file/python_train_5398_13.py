n, k = map(int, input().split())
a = list(map(int, input().split()))

res = 1<<60
for i in range(1<<n):    
    if i % 2 == 0: continue

    use_idx = [0 for _ in range(n)]
    use_cnt = 0
    for j in range(n):
        if i & (1<<j):
            use_idx[j] = 1
            use_cnt += 1
    
    if use_cnt != k: continue

    sm = 0
    mx = a[0]
    for j in range(1, n):
        if use_idx[j]:
            if a[j] <= mx:
                sm += mx+1 - a[j]
                mx += 1
        mx = max(mx, a[j])
    
    res = min(res, sm)

print(res)