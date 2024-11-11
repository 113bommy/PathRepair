def func2( number ):
    if number == 1:
        return ( -1, 0, 0 )
    if number == 2:
        return ( -1, 0, 0 )
    if number == 3:
        return ( 0, 0, 1 )
    if number == 4:
        return ( -1, 0, 0 )
    if number == 5:
        return ( 0, 1, 0 )
    if number == 6:
        return ( 0, 0, 2 )
    if number == 7:
        return ( 1, 0, 0 )
    if number == 8:
        return ( 0, 1, 1 )
    if number == 9:
        return ( 0, 0, 3 )
    if number == 10:
        return ( 0, 2, 0 )
    if number == 11:
        return ( 0, 1, 2 )
    if number == 12:
        return ( 0, 0, 4 )
    if number == 13:
        return ( 0, 2, 1 )
    if number == 14:
        return ( 2, 0, 0 )
    if number == 15:
        return ( 0, 3, 0 )
    if number == 16:
        return ( 0, 2, 2 )
    if number == 17:
        return ( 1, 2, 0 )
    if number == 18:
        return ( 0, 3, 1 )
    if number == 19:
        return ( 0, 3, 3 )
    if number == 20:
        return ( 0, 4, 0 )

def func():
    n = int( input() )
    n7 = 0
    n5 = 0
    n3 = 0
    if ( n <= 10 ):
        (n7, n5, n3 ) = func2( n )
    else:
        x = n % 10
        y = n // 10
        if x <= 4:
            y = y - 1
            x = x + 10
        (n7, n5, n3 ) = func2( x )
        n5 = n5 + ( y * 2 )
    if ( n7 == -1 ):
        print ( -1 )
        return
    print ( n3, n5, n7 )
    return
    

def codeforces1430ProblemB():
    x = [ int(i) for i in input().split(" ") ]
    n = x[0]
    k = x[1]

    tanks = []
    tanks = [ int(i) for i in input().split(" ") ]
    sorted( tanks )
    maxDiff = tanks[n-1]
    # n > 2
    if tanks[n-1] == 0:
        print (0)
        return
    for i in range( k ):
        maxDiff = maxDiff + tanks[(n-1)-(i+1)]
    print ( maxDiff )
    return
    
numTest = int( input() )
while numTest:
    numTest -= 1
    codeforces1430ProblemB()
