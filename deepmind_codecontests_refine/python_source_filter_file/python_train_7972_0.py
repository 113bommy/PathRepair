from functools import cmp_to_key

N = int( input() )
A = list( map( int, input().split() ) )
B = list( map( int, input().split() ) )

ord = sorted( list( i for i in range( N ) ), key = cmp_to_key( lambda x, y: A[ x ] - A[ y ] ) )

ans = [ ord[ 0 ] ]
for i in range( 1, N, 2 ):
  if i + 1 == N:
    ans.append( ord[ i ] )
  else:
    if B[ ord[ i ] ] >= B[ ord[ i + 1 ] ]:
      ans.append( ord[ i ] )
    else:
      ans.append( ord[ i + 1 ] )

print( len( ans ) )
print( *list( map( lambda x: x + 1, ans ) ) )
