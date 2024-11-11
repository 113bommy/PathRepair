n, k = list( map( int, input().split()))
p = list( map( int, input().split()))
c = list( map( int, input().split()))

m = {}
for i in range( n ):
    if p[ i ] not in m:
        m[ p[ i ] ] = list()
    m[ p[ i ] ].append( c[ i ] )

a = {}
t = []
for key, val in sorted( m.items() ):
    a[ key ] = sum( t )
    t += val
    t.sort()
    t = t[ max( 0, len( t ) - k ) : len( t ) ]

print( " ".join( [ str( a[ p[ i ] ] + c[ i ] ) for i in range( n )]))
