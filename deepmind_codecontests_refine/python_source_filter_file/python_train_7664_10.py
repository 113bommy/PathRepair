c = int(input())
d = {}
t = {}
for i in range(c):
    s = input().split()
    if s[0] not in t:
        t[s[0]] = []
    for m in s[2:]:
        t[s[0]].append(m)
for i in t:
    d[i] = []
    u = set(t[i])
    q = []
    for p in u:
        q.append(p)
    for j in range(len(q)):
        a = q[j][::-1]
        z = 0
        for k in range(len(q)):
            b = q[k][::-1]
            if j!=k and b.find(a)!=-1:
                if b.find(a) == 0:
                    z = 1
                    break
        if z == 0:
            d[i].append(a)
print(len(d))    
for i in d:
    print(i,len(d[i]),end = ' ')
    for j in d[i]:
        print((j),end = ' ')
    print('\n')
