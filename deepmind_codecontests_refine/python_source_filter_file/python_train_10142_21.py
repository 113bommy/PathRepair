c, d = map(int,input().split())
if(c==d):
    print(0, 6, 0)
else:
    a = min(c, d)
    b = max(c, d)
    
    first = a+(b-a-1)//2
    second = 6-b+1 + (b-a-1)//2
    draw = abs(6-second+first)
    if(c<d):
        print(first, draw, second)
    else:
        print(second, draw, first)
