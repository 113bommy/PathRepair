def f(l):
    x,y = l
    yy  = y+x if y*x>0 else y-x
    xx  = x+y if y*x>0 else x-y
    return [xx,0,0,yy] if xx<0 else [0,yy,xx,0]

l = list(map(int,input().split()))
print(f(l))
