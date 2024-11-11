N, K = map(int, input().split())
P = [0] + list(map(int, input().split()))
C = [0] + list(map(int, input().split()))
ans = -float('inf')
for i in range(1, N+1):
    v = i
    score = 0
    size = 0
    while True:
        size += 1
        score += C[v]
        if i == P[v]:
            break
        v = P[v]

    if score > 0:
        tmp = score*(K//size-1)
        num = K%size+size
    else:
        tmp = 0
        num = min(K, size)
    
    v = i
    for _ in range(num):
        tmp += C[v]
        v = P[v]
        ans = max(tmp, ans)

print(ans)