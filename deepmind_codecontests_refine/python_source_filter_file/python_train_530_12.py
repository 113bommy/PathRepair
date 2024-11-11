from math import ceil
t = int( input() )

for tc in range( t ):
    n, m = map( int, input().split() )
    w = n * m - ( ( n * m ) >> 1 )

    x1,y1,x2,y2 = map(int,input().split())
    x3,y3,x4,y4 = map(int,input().split())

    sz = (x2-x1+1)*(y2-y1+1)
    tw = sz >> 1
    if sz & 1 > 0 and ( x1 + y1 ) & 1 > 0:
        tw = sz - tw

    sz = (x4-x3+1)*(y4-y3+1)
    tb = sz >> 1
    if sz & 1 > 0 and ( x3 + x4 ) & 1 == 0:
        tb = sz - tb

    x1 = max( x1,x3 )
    x2 = min( x2, x4 )
    y1 = max( y1, y3 )
    y2 = min( y2, y4 )

    sz = (x2-x1+1)*(y2-y1+1)
    ctw = sz >> 1
    if sz & 1 > 0 and ( x1 + y1 ) & 1 > 0:
        ctw = sz - ctw
    if x1 > x2 or y1 > y2:
        ctw = 0

    w += tw - tb - ctw
    print( w, n * m - w )

