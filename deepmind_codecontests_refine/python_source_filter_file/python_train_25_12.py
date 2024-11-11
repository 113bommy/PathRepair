t = int(input())

for _ in range(t):
    n = int(input())
    m = []
    for _ in range(n):
        m.append(input())
    a, b, c, d = m[1][0], m[0][1], m[-1][-2], m[-2][-1]
    t = 8*int(a) + 4*int(b) + 2*int(c) + 1*int(d)

    a2 = 0

    if t in [0, 15]:
        a2 = [(1,2),(2,1)]
    elif t in [1, 14]:
        a2 = [(n, n-1)]
    elif t in [2, 13]:
        a2 = [(n-1, n)]
    elif t in [3, 12]:
        a2 = []
    elif t in [4,11]:
        a2 = [(2,1)]
    elif t in [5, 10]:
        a2 = [(1,2),(n-1,n)]
    elif t in [6, 9]:
        a2 = [(1,2),(n,n-1)]
    elif t in [7, 8]:
        a2 = [(1,2)]
    
    print(len(a2))
    for e in a2:
        print(e[0], e[1])

