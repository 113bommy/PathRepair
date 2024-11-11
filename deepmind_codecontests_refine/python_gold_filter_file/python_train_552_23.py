t, k = [int(a) for a in input().strip().split()]
l = []
for i in range(t):
    n, p = [int(a) for a in input().strip().split()]
    l.append(n*100+100-p)
l.sort(reverse=True)
c=0
for i in range(t):
    if int(l[k-1]) == int(l[i]):
        c += 1
print(c)