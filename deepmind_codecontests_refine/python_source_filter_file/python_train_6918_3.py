n, m = [int(i) for i in input().split()]
days = [0]*n
for i in range(m):
    s, f = [int(k) for k in input().split()]
    for k in range (f - s + 1):
        days[s - 1 + k] +=1
n = -1
for i in range(m):
    if days[i] != 1:
        n = i + 1
        m = days[i]
        break
if n == -1:
    print("OK\n")
else:
    print("%d %d\n" % (n, m))
