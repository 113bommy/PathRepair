n, t = [int(i) for i in input().split()]
ab = []
for _ in range(n):
    ab.append([int(i) for i in input().split()])
sb.sort(key=lambda x:x[0])
aa = t+max([i[0] for i in ab])+1
c = [0] * aa
for i in ab:
    d = c[:]
    for j in range(t):
        k = d[j]
        l = i[0] + j
        if l >= aa:
            continue
        c[l] = max(c[l], d[j] + i[1])
print(max(c))
