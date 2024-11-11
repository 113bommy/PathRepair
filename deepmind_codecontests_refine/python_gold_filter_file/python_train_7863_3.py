n = int(input())
a = list(map(int,input().split()))
def func(b,p):
    if len(b) == 1:
        if p == 0:
            if b[0] == 0:
                return 1
            else:
                return 0
        elif p == 1:
             if b[0] == 0 or b[0] == 1:
                return 1
             else:
                return 0
        elif p == 2:
             if b[0] == 0 or b[0] == 2:
                return 1
             else:
                return 0
        else:
             if b[0] == 0:
                return 1
             else:
                return 0
    else:
        c = b[1:]
        if p == 0:
            if b[0] == 0:
                return 1 + func(c,0)
            else:
                return func(c,b[0])
        elif p == 1:
             if b[0] == 0 or b[0] == 1:
                return 1 + func(c,0)
             else:
                return func(c,2)
        elif p == 2:
             if b[0] == 0 or b[0] == 2:
                return 1 + func(c,0)
             else:
                return func(c,1)
        else:
            if b[0] == 0:
                return 1 + func(c,0)
            else:
                return func(c,b[0])
print(func(a,0))