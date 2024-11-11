t = int(input())
z = []
for i in range(t):
    n = int(input())
    b  = input()
    p = 0
    for j in range(len(b)):
        for k in range(1,len(b)+1):
            if b[j:k].count('a')==b[j:k].count('b') and j<k:
                r = []
                r.append(j+1)
                r.append(k)
                q = j
                w = k
                z.append(r)
            else:
                p = p+1
    if p==len(b)**2:
        z.append([-1,-1])
    z = z[0:i+1]
for y in z:
    print(*y)