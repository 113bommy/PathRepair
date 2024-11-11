a,b = map(int,input().split())
c,d = map(int,input().split())
e,f = map(int,input().split())
# Collinear
if((a == c == e) or (b == d == f)):
    print(1)
elif((a==c or c == e or a == e) or (b == d or d == f or f ==b)):
    three = True
    if(a == c):
        lis = sorted([b,d])
        if(f <= lis[0] or f >= lis[1]):
            three = False
    if(c == e):
        lis = sorted([d, f])
        if(b <= lis[0] or b >= lis[1]):
            three = False
    if(a == e):
        lis = sorted([b,f])
        if(d <= lis[0] or d >= lis[1]):
            three = False
    if(b == d):
        lis = sorted([a,c])
        if(e <= lis[0] or e >=lis[1]):
            three = False
    if(d == f):
        lis = sorted([c,e])
        if(a <= lis[0] or a >= lis[1]):
            three = False
    if(f == b):
        lis = sorted([a, e])
        if(c <=lis[0] or c >= lis[1]):
            three = False
    if(three):
        print(3)
    else:
        print(2)
    
else:
    print(3)