N,K,Q,*A = map(int, open(0).read().split())
ans = [K] * N

for a in A:
    ans[a-1] += 1

for x in ans:
    y = x - Q
    print('Yes' if x > 0 else 'No')
