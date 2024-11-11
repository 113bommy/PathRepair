for _ in range(int(input())):
    a, b=map(int, input().split())
    d=abs(a-b)
    if d%5<3:
        print((d//5)+1)
    elif d%5>2:
        print((d//5)+2)
    else:
        print(d//5)
