n, *t = map( int, open( 0 ).read().split() )

# manemane
A, B, C = 0, 0, 0
for i in  range( n ):
  A, B, C = t[ 3 * i  ] + max( B, A ), t[ 3 * i + 1 ] + max( A, C ), t[ 3 * i + 2 ] + max( A, B )

print( max( A, B, C ) )
