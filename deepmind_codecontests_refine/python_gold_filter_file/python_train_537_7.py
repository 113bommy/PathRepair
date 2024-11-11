def delRep(a):
    for i in a:
        while a.count(i) > 1:
            a.reverse()
            a.remove(i)
            a.reverse()
    return a


s = []
s1 = []
t = int(input())
for i in range(t):
    n, k, d = map(int, input().split())
    alfa = list(map(int, input().split()))
    if len(alfa) > d:
        for i1 in range(len(alfa)-d+1):
            s1.append(len(delRep(alfa[i1:i1+d])))
    else:
        s1.append(len(delRep(alfa)))
    s.append(min(s1))
    alfa.clear()
    s1.clear()
for i in s:
    print(i)




