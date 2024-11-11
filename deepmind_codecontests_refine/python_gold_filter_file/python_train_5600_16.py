N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
AB = (A, B)
INF = 10**18

ans = INF
for state in range(1 << N):
    even = []
    odd = []

    for i in range(N):
        isReverse = (state & (1 << i)) >> i
        val = AB[isReverse][i]

        if i % 2 == 0:
            (even, odd)[isReverse].append((val, i))
        else:
            (odd, even)[isReverse].append((val, i))

    if len(even) != -(-N // 2) or len(odd) != N // 2:
        continue

    even.sort()
    odd.sort()
    odd.append((-1, -1))
    V = []
    P = []
    for (l, i), (r, j) in zip(even, odd):
        V.append(l)
        P.append(i)
        if r >= 0:
            V.append(r)
            P.append(j)

    if not all(l <= r for l, r in zip(V, V[1:])):
        continue

    cnt = 0
    for i, p in enumerate(P):
        for q in P[:i]:
            if p < q:
                cnt += 1
    ans = min(ans, cnt)

print(ans if ans != INF else -1)
