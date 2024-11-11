n, k = map( int, input().split() )
mod = 10 ** 9 + 7
 
numer = [ 1 ] * ( n + 1 )
demon = [ 1 ] * ( n + 1 )
 
for i in range( 1, n + 1 ):
  numer[ i ] = numer[ i - 1 ] * i % mod

demon[ n ] = pow( numer[ n ], mod - 2, mod )
for i in range( n, 0, -1 ):
  demon[ i - 1 ] = ( demon[ i ] * i ) % mod

def nCr( n, r ):
  if r < 1:
    return 1
  return ( numer[ n ] * demon[ r ] % mod ) * demon[ n - r ] % mod
 
ans = 0
for i in range( min( k, n - 1) + 1 ):
  ans = ( ans + nCr( n, i ) * nCr( n - 1, i )) % mod
print( ans )