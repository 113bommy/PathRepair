while(True):
    n = int(input())
    if n==0: break
    d = {}
    c = 0
    l = list()
    for _ in range(n):
        id_,p,q = map(int,input().split())
        if id_ in d:
            d[id_] += p*q
        else:
            d[id_] = p*q
            l.append(id_)
    for i in d:
        if d[i] >= 1000000:
            print(i)
            c += 1
    if c == 0:
        print('NA')