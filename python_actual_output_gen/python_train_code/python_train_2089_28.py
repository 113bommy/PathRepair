for _ in range(int(input())):
    n,m = map(int,input().split())
    d = 0
    l = list(map(int,input().split()))
    if sum(l[0:]) <= m:
        print(m)
    else:
        d = abs(sum(l) - m)
        print(sum(l)-d)