n = int(input())
p = [int(input()) for _ in range(n)]

q = [0] * (n+1)
for i in range(n):
    q[p[i]] = q[p[i]-1] + 1

print(n - max(q))
