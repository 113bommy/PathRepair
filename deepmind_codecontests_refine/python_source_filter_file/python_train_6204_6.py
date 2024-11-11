N = int( input() )
x1, y1, x2, y2 = map( int, input().split() )
maxl, minr = 0.0, 1e30
for i in range( N ):
  rx, ry, vx, vy = map( int, input().split() )
  c = [ 0.0 for i in range( 4 ) ] # b, t, l, r
  if vx == 0:
    if not ( x1 <= rx and rx <= x2 ):
      exit( print( -1 ) )
    else:
      c[ 2 ] = 0.0
      c[ 3 ] = 0.0
  else:
    c[ 2 ] = ( x1 - rx ) / vx
    c[ 3 ] = ( x2 - rx ) / vx
  if vy == 0:
    if not ( y1 <= ry and ry <= y2 ):
      exit( print( -1 ) )
    else:
      c[ 0 ] = 0.0
      c[ 1 ] = 0.0
  else:
    c[ 0 ] = ( y1 - ry ) / vy
    c[ 1 ] = ( y2 - ry ) / vy
  for j in range( 2 ):
    xx = rx + c[ j ] * vx
    if not ( x1 <= xx and xx <= x2 ):
      c[ j ] = -1.0
  for j in range( 2, 4, 1 ):
    yy = ry + c[ j ] * vy
    if not ( y1 <= yy and yy <= y2 ):
      c[ j ] = -1.0
  ll, rr = 1e30, 0.0
  for j in range( 4 ):
    if c[ j ] < 0.0: continue
    ll = min( ll, c[ j ] )
    rr = max( rr, c[ j ] )
  if x1 < rx and rx < x2 and y1 < ry and ry < y2:
    if vx == 0 and vy == 0: continue # mugen
    minr = min( minr, rr )
    continue
  if ll == 1e30 or ll == rr:
    exit( print( -1 ) )
  maxl = max( maxl, ll )
  minr = min( minr, rr )

if minr < maxl:
  print( -1 )
else:
  print( "%.8f" % maxl )
