n = int( input() )

if n <= 2:
	print( 1 )
	exit(0)

F = [1,1]

while F[-1] < n:
	F.append( F[-1] + F[-2] )
	
s = 0
for i in range( len(F) ):
	s += F[i]
	if s > n:
		print( i )
		break