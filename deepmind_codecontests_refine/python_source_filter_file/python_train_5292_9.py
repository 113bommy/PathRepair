N = int(input())
ans = 0
mi = float("inf")
for _ in range(N):
    A, B = map(int, input().split())
    if A>=B:
        mi = min(mi, B)
    ans += B
print(ans - mi if mi != float("inf") else 0)
