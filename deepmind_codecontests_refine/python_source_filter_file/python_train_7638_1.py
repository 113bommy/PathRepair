n, m, d = [int(i) for i in input().split()]
M = []
for i in range(n):
    M += [int(j) for j in input().split()]
mod = M[0] % d
r = 1
for i in M:
    if i % d != mod:
        r = 0
        print(-1)
        break
if r:
    M.sort()
    medium = M[n * m // 2 - 1]
    count = 0
    for i in M:
         count += abs(medium - i)
    print(int(count/d))