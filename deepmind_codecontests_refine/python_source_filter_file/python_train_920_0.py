N,X = map(int,input().split())
A = list(map(int,input().split()))

ans = sum(A)
costs = A[:]
for i in range(1,N):
    cost = i*X
    if cost >= ans: break
    for j in range(N):
        costs[j] = min(costs[j], costs[(j-i)%N])
        cost += costs[j]
    ans = min(ans, cost)

print(ans)