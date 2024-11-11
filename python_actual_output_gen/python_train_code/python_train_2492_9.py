T = int(input().strip())

debug = False

for t in range(T):
    a,b,x,y = map(int, input().split())
    
    if (x==0 and y==0) or (x==(a-1) and y==0) or (x==(a-1) and y==(b-1)) or (x==0 and y==(b-1)):
        print(max((a-1)*b, a*(b-1)))
    elif (x==0 or x==(a-1)) and 0<y<(b-1):
        print(max( (a-1)*b, a*(y), a*(b-(y+1)) ) )
    elif (y==0 or y==(b-1)) and 0<x<(a-1):
        print( max( a*(b-1), b*(x), b*(a-(x+1))  ) )
    else:
        print( max(a*(y), a*(b-(y+1)), (x), b*(a-(x+1))    ) )