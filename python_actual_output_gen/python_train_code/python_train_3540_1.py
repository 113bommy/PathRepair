N = int(input())
A = list(map(int, input().split()))

avg = sum(A) // N
ans = 0
for i, a in enumerate(A):
    ans += (a - avg) ** 2

print(ans)
