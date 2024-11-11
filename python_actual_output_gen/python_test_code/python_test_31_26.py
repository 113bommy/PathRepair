x,y=[int(a) for a in input().split()]
if (x<=7):
    if (x%2==0):
        if (x!=2):
            if (x==7):
                d=6
            else:
                d=5
        else:
            if (y==1):
                d=4
            else:
                d=5
    else:
        if (y>=6):
            d=6
        else:
            d=5
else:
    if (x%2==0):
        if (y>=6):
            d=6
        else:
            d=5
    else:
        if (y==7):
            d=6
        else:
            d=5
print(d)