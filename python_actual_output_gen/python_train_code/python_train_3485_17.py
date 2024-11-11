for i in range(int(input())):
    n = int(input())
    s = ""
    f = 0
    for t in range(n):
        inp = input()
        s = s + inp
    se = set(s)
    l = []
    for j in se:
        l.append(s.count(j))

    m = min(l)
    for k in l:
        if k%m!=0:
            f = 1
            break
    if f==0:
        print("YES")
    else:
        print("NO")