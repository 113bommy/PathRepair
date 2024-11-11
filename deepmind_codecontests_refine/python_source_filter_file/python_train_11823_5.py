a, b, c = map( int, input().split() )

Minim = 0
idx = 0

for i in range( 1, 101 ):
	tmp = abs( a - i ) + abs( b - i ) + abs( c - i )
	
	if i == 1 or Minim > tmp:
		Minim = tmp
		idx = i
		
print( idx )