n, k, l, r, sall, sk = map(int, input().split())
scores, remaining = [], sall - sk

for i in range(1, k):
    scores.append(sk // k)
    if sk % k != 0:
        scores[-1] += 1
        sk -= 1

if k != n:
    for i in range(k, n - 1):
        scores.append(remaining // (n - k))
        if remaining % (n - k) != 0:
            scores[-1] += 1
            remaining -= 1

print(" ".join(map(str, scores)))
