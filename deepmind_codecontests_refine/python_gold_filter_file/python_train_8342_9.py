def get(arr):
    r = 0
    c = 0
    for i in arr:
        if i[0] > r:
            c += 1
            r = i[1]
    return c        
    
n = int(input())
a = [int(x) for x in input().split()]
p = [0]
d = {}
for i in a:
    p.append(p[-1] + i)
for i in range(len(p)):
    for j in range(i, len(p)):
        if i != j:
            r = p[j] - p[i]
            d[r] = d.get(r, []) + [(i + 1, j)]
s = 0
for i in d:
    k = sorted(d[i], key=lambda x: x[1])
    if get(k) > s:
        s = get(k)
        ind = k
r = 0
print(s)
for i in ind:
    if i[0] > r:
        print(i[0], i[1])
        r = i[1]