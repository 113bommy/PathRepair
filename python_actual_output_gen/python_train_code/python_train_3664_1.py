N, p = map(int, input().split())
l = [0 for i in range(N+1)]
r = [0 for i in range(N+1)]
for i in range(N):
    lx, rx = map(int, input().split())
    l[i] = lx; r[i] = rx
l[N] = l[0]; r[N] = r[0]

a1 = r[0] // p - (l[0] - 1) // p
n1 = r[0] - l[0] + 1
t1 = (n1-a1) / n1
ans = 0
for i in range(N):
    a2 = r[i] // p - (l[i] - 1) // p
    n2 = r[i] - l[i] + 1
    t2 = (n2-a2) / n2
    
    ans += 1 - t1 * t2
    
    t1 = t2

print(2000 * ans)