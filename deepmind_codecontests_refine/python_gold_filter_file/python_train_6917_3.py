n, m = [int(i) for i in input().split()]
days = [0] * n
for i in range(m):
    s, f = [int(k) for k in input().split()]
    for k in range (f - s + 1):
        days[s - 1 + k] +=1
m = -1
for i in range(n):
    if days[i] != 1:
        m = i + 1
        n = days[i]
        break
if m == -1:
    print("OK\n")
else:
    print("%d %d\n" % (m, n))
