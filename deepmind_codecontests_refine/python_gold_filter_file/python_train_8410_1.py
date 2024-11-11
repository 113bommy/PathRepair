N, K = map(int, input().split())
*A, = map(int, input().split())
A.sort()

S = sum(A)
candidates = []
for i in range(1, int(S**0.5)+1):
    if S%i:continue
    a, b = i, S//i
    
    candidates.append(a)
    if a!=b:
        candidates.append(b)
candidates.sort()

ans = 0
for d in candidates:
    rems = []
    rems_size, rems_sum = 0, 0

    for i in A:
        if i%d:
            rems.append(i%d)
            rems_size += 1
            rems_sum += i%d

    rems.sort()

    a = 0
    for i, j in enumerate(rems[:-1], start=1):
        a += j
        b = d*(rems_size-i)-(rems_sum-a)
        if max(a, b)<=K:
            ans = max(ans, d)
    if not rems:
        ans = max(ans, d)

print(ans)