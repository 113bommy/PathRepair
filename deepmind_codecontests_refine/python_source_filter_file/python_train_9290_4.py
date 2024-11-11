for _ in range(int(input())):
    a1,b1 = map(int,input().split())
    a2,b2 = map(int,input().split())
    x = min(a1,b1)
    y = min(a2,b2)
    if max(max(a1,b1),max(a2,b2)) == x+y:
        print('Yes')
    else:
        print('No')