t = int(input())
for i in range(t):
    x1, p1 = [int(f) for f in input().split(" ")]
    x2, p2 = [int(f) for f in input().split(" ")]
    c1 = 0
    c2 = 0
    temp1 = 0
    temp2 = 0
    for i in range(6,0,-1):
        if x1//10**i >= 1 and temp1 == 0:
            c1 = i
            temp1 = 1
        if x2//10**i >= 1 and temp2 == 0:
            c2 = i
            temp2 = 1
    if x1 > x2:
        if c1+p1 > p2+c2:
            print('>')
        elif c1+p1==c2+p2:
            if x2*10**(abs(p1-p2))>x1:
                print("<")
            elif x2*10**(abs(p1-p2))<x1:
                print(">")
            else:
                print("=")
        else:
            print('<')
    elif x1 < x2:
        if c1+p1 < p2+c2:
            print("<")
        elif c1+p1==c2+p2:
            if x1*10**(abs(p1-p2))>x2:
                print(">")
            elif x1*10**(abs(p1-p2))<x2:
                print("<")
            else:
                print("=")
        else:
            print(">")
    else:
        if p1 > p2:
            print(">")
        elif p2 < p1:
            print("<")
        else:
            print("=")
