n, k = [int(x) for x in input().split(' ')]
t = [int(x) for x in input().split(' ')]
e = sum(t)
m = 0
for i in range(n):
    e_l = sum([z for (j, z) in enumerate(t) if j % k != i])
    m = max(abs(e_l), m)
print(m)