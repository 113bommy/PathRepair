a = input()

n = len( a )

ans = -1

for i in range( 26 ):
	c = chr( 97 + i )
	
	last = 0
	tmp = 0
	
	for i in range( n ):
		if a[i] == c:
			tmp = max( tmp, i - last )
			last = i
			
	tmp = max( tmp, n - last )
	
	if ans == -1:
		ans = tmp
	else:
		ans = min( ans, tmp )
		
print( ans )