n, l, r = list(map(int, input().split()))
mod = int(1e9 + 7)
m0 = r // 3 - (l - 1) // 3
m1 = (r + 2) // 3 - (l + 1) // 3
m2 = (r + 1) // 3 - (l) // 3
a0 = 1
a1 = 0
a2 = 0
# print(m0, m1, m2)
for i in range(n):
    t0 = (a0 * m0 + a1 * m2 + a2 * m1) % mod
    t1 = (a0 * m1 + a1 * m0 + a2 * m2) % mod
    t2 = (a0 * m2 + a1 * m1 + a2 * m0) % mod
    a0, a1, a2 = t0, t1, t2
    # print(a0, a1, a2)
print(a0)