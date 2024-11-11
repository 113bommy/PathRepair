def main():
	n = int( input() )
	s = input()
	ans = 0
	cnt = [ 0 ] * 26
	for i in range( 0, 2*n - 2, 2 ):
		cnt[ ord( s[ i ] )- ord('a') ] += 1
		if cnt[ ord( s[ i+1 ] )- ord('A') ] == 0:
			ans += 1
		else:
			cnt[ ord( s[ i ] )-ord('a') ] -= 1
	print( ans )

main()