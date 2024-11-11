T = input()
for t in range(int(T)):
    ss = input().split(' ')
    a = int(ss[0])
    b = int(ss[1])
    c = int(ss[2])
    t1 = 0
    t2 = 0
    t3 = 0
    if a % 2 == 1:
        t1 = 1
    if b % 2 == 1:
        t2 = 1
    if c % 2 == 1:
        t3 = 1
    if t1 and t2 and t3:
        print(0)
    elif t1 and t2:
        print(1)
    elif t1 and t3:
        if a >= 2:
            print(0)
        else:
            print(2)
    elif t2 and t3:
        print(1)
    elif t1:
        print(1)
    elif t2:
        if a >= 2:
            print(0)
        else:
            print(2)
    elif t3:
        if a >= 2 or b >= 2:
            print(1)
        else:
            print(3)
    else:
        print(0)