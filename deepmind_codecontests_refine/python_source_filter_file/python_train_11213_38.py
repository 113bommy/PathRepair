n = int(input())
v = list(map(int,input().split()))

if n == 1:
    print(-1)
elif n == 2:
    if v[0] == v[1]:
        print(-1)
    else:
        print(1)
        print(0)
elif n > 2:
    new = sorted(v)
    gs = new[0]
    print(1)
    print(v.index(gs))
