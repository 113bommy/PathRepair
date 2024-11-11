t = int( input() )
def countAns( n , r ) :
	x = min( n - 1 , r )
	return (x + 1) * x // 2 + int( n < r )

for _ in range( t ) :
	n , r = list( map( int , input().split() ) )
	print( countAns( n , r ) )
