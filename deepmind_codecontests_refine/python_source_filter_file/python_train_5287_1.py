N = int(input())
A = list(map(int, input().split()))

d = [0]*N
ans = 0
for i in range(N):
    a = A[i]
    l,r = i+a, i-a
    if 2 <= l < N:
        d[l] += 1
    if 2 <= r < N:
        ans += d[r]

print(ans)
