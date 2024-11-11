N, x = map(int, input().split())
*A, = map(int, input().split())
MAX = 10**18
B = [MAX]*N
ans = MAX
for k in range(N):
    for i in range(N):
        B[i] = min(B[i], A[(i-k) % N])
    ans = min(ans, k*x + sum(B))
print(ans)