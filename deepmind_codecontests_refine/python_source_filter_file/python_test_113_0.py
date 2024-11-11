for _ in range(int(input())):
    x,p = map(int,input().split())
    y,q = map(int,input().split())
    if len(str(x))+p > len(str(y))+q:
        print(">")
    elif len(str(x))+p < len(str(y))+q:
        print("<")
    else:
        if p > q:
            x = x*(10**(p-q))
        if q < p:
            y = y*(10**(q-p))
        if x > y:
            print(">")
        elif y > x:
            print("<")
        else:
            print("=")