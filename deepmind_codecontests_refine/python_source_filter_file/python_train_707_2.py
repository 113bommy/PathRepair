K = int(input())

def S(x) :
    ret = 0
    while x :
        ret += x % 10
        x //= 10
    return ret

L = set()
nine = ''
for i in range(16) :
    for j in range(1, 100) :
        x = int(str(j) + nine)
        L.add(x)
    nine += '9'
    
L = list(L)
L.sort()

v = [1]
n = [1]

for l in L[1:] :
    x = l / S(l)
    while v[-1] > x :
        v.pop()
        n.pop()
    v.append(x)
    n.append(l)

for i in range(K) :
    print(n[i])
