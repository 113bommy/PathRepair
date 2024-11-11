t = int( input() )
for i in range(t):
    n, m, x1, y1, x2, y2 = map( int, input().split() )
    #print(n,m,x1,y1,x2,y2)
    l = min( x1-1, x2-1 )
    r = min( n-x1, n-x2 )
    d = min( y1-1, y2-1 )
    u = min( m-y1, m-y2 )
    #print(l,r,d,u)
    srange = [ ( x1-l, x1+r, y1-d, y1+u ), ( x2-l, x2+r, y2-d, y2+u ) ]
    sortRan = sorted( srange, key = lambda e: e[0] )
    s = (l+r+1) * (d+u+1) * 2
    #print(sortRan)
    #print(s)
    if sortRan[1][0] <= sortRan[0][1]:
        if sortRan[0][2] <= sortRan[1][3] <= sortRan[0][3]:
            s -= (sortRan[0][1] - sortRan[1][0] + 1) * ( sortRan[1][3] - sortRan[0][2] + 1)
        elif sortRan[0][2] <= sortRan[1][2] <= sortRan[0][3]:
            s -= (sortRan[0][1] - sortRan[1][0] + 1) * ( sortRan[0][3] - sortRan[1][2] + 1)
    print( n*m - s )
