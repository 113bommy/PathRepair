for _ in range(int(input())):
    a,b,c = map(int,input().split())
    p,q = -1, -1
    if a*b>c and a>c:
        p =-1 
        q = b
    if a*b >c and a<c:
        p = 1
        q = b
    if a*b==c and (a<c or a>c):
        p = 1
        q = -1
    if a*b<c and a<c:
        p = b+1
        q = -1
    print(p, q)