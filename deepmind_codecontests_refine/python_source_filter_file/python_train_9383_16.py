N, K, M = map(int, input().split())
a = sorted(map(int, input().split()))
total = sum(a)
ans = (total+min(K, M)) / N

for n in a:
    if not M or N == 1:
        break
    M -= 1
    N -= 1
    total -= n
    ans = max(ans, (total+min(K, M)) / N)

print(ans)