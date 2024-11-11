n = int(input())

m = [int(i) for i in input().split()]

for i in range(n):
    if m[i] >= 0:
        m[i] = -1 * m[i] - 1

if len(m) % 2 == 1:
    ind = m.index(min(m))
    m[ind] = -1 * m[ind] - 1

print(*m)