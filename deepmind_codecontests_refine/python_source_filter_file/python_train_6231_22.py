n, m = map( int, input().split() )
edge_list = []
for _ in range( m ):
    a_i, b_i, c_i = map( int, input().split() )
    edge_list.append( ( a_i - 1, b_i - 1, - c_i ) )

INF = 10 ** 10
cost = [ INF ] * n
cost[ 0 ] = 0

NegativeLoopExist = False
for i in range( n ):
    for j in range( m ):
        a, b, c = edge_list[ j ]
        if cost[ a ] != INF and cost[ b ] > cost[ a ] + c:
            cost[ b ] = cost[ a ] + c
            if i == n - 1 and b == n - 1 :
                NegativeLoopExist = True

if NegativeLoopExist:
    print( "inf" )
else:
    print( - cost[ n - 1 ] )