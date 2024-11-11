n, k = map(int, input().split())
A = list(map(int, input().split()))

ans = 10 ** 10
for b in range(1 << n):
    if bin(b).count("1") != k:
        continue

    max_ai = 0
    cost = 0
    for i in range(n):
        if (b & 1 << i):
            if A[i] > max_ai:
                max_ai = A[i]
            else:
                cost += (max_ai + 1) - A[i]
                max_ai += 1
        else:
            max_ai = max(max_ai, A[i])

    ans = min(ans, cost)

print(ans)


