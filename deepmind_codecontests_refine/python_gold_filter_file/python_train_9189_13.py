for _ in range(int(input())):
    a,b,c,d = map(int,input().split())
    x = abs(a-c)
    y = abs(b-d)
    if a==c or b==d:total = x+y
    else: total = x+y+2
    print(total)