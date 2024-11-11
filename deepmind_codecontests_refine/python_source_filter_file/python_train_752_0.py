def toTernary(n):
    i = 0
    while(3**i < n):
        i+=1
    i-=1
    ternary = []
    while(i>=0):
        multi = (n//3**i)
        ternary.append(multi)
        n -= multi * 3**i
        i-=1
    return ternary
def sameLen(t1, t2):
    l1 = len(t1)
    l2 = len(t2)
    dif = abs(l1 - l2)
    nL = []
    for i in range(dif):
        nL.append(0)
    if l1 == l2:
        return t1, t2
    elif l1 < l2:
        t1 = nL + t1
        return t1, t2
    elif l1 > l2:
        t2 = nL + t2
        return t1, t2
ac = list(map(int, input().split()))
a = ac[0]
c = ac[1]
aT = toTernary(a)
cT = toTernary(c)
#print(a, aT, c, cT)
aT, cT = sameLen(aT, cT)
#print(aT, cT)
bT = []
for i in range(len(aT)):
    b = cT[i] - aT[i]
    if(b<0):
        b = 3 + b
    bT.append(b)
#print(bT)
b = 0
for i in range(len(bT)):
    b += (3**(len(bT)-i-1))*bT[i]
print(b)

