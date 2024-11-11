t = int(input())
for i in range(t):
    l = int(input())
    data = list(map(int,input().split()))
    m = max(data)
    a = sorted(data[:m])
    b = sorted(data[m:])
    c = sorted(data[:l-m])
    d = sorted(data[l-m:])
    e = [i for i in range(1,m+1)]
    f = [i for i in range(1,l-m+1)]
    if m!=l/2:
        if (a==e and b==f) and (c==f and d==e):
            print(2)
            print(m,l-m)
            print(l-m,m)
        elif ((a==e and b==f) and (c!=f or d!=e)):
            print(1)
            print(m,l-m)
        elif ((a!=e or b!=f) and (c==f and d==e)):
            print(1)
            print(l-m,m)
        else:
            print(0)
            
    else:
        if (a==e and b==f) or (c==f and d==e):
            print(1)
            print(m,m)
        else:
            print()