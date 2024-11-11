n,k,x = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]

m = 0

def scan(l,m):
    if len(l) == 0:
        return l,m
    mstart = 0
    mle = 1
    start = 0
    col = l[0]
    le = 1
    for i in range(1,len(l)):
        if l[i] == col:
            le += 1
        else:
            if le > mle:
                mle = le
                mstart = start
            col = l[i]
            start = i
            le = 1
    if le > mle:
        mle = le
        mstart = start
    if mle < 3:
        return l,m
    #print(mle,mstart,l)
    m += mle
    l = l[:mstart] + l[mstart+le+1:]
    #print(l)
    return l,m

for i in range(n+1):
    l2 = l[:]
    m2 = -1
    l2 = l2[:i] + [x] + l2[i:]
    
    while True:
        l2, m3 = scan(l2, m2)
        if m2 == m3:
            break
        m2 = m3
    #print(m2)
    #print()
    m = max(m,m2)
print(m)
