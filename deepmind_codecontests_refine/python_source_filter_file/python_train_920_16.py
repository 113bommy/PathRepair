from collections import Counter
def inpl(): return list(map(int, input().split()))
N, x = inpl()
A = inpl()
B = [a for a in A]

ans = 1e10
for i in range(N+1):
    for j in range(N):
        B[j] = min(B[j], A[(j-i)%N])
    tmp = x*i + sum(B)
    ans = min(ans, tmp)
print(ans)
