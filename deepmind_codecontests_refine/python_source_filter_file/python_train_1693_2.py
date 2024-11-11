for _ in range(int(input())):
    n = int(input())
    a = input()
    b = input()
    o = []
    p = []
    l = []
    for i in range(n):
        o.append(a[i])
        p.append(b[i])
    for i in range(n-1,-1,-1):
        if o[i]==p[i]:
            continue
        if o[0]==p[i]:
            l.append(1)
            if o[0]=='0':
                o[0]='1'
            else:
                o[0]='0'
        l.append(i+1)
        for j in range(i+1):
            if o[j]=='1':
                o[j]='0'
            else:
                o[j]='1'
        for j in range(i//2):
            t = o[j]
            o[j] = o[i-j]
            o[i-j] = t
    print(len(l),end=" ")
    for k in range(len(l)):
        print(l[k],end=" ")
    print()