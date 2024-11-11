n, k = [ int( val ) for val in raw_input( ).split( " " ) ]
w = [ int( raw_input( ) ) for val in range( n ) ]
sumW = sum( w )
maxW = max( w )

minP = 0
if 1 == k:
	minP = sumW
elif n == k:
	minP = maxW
else:
	left = maxW
	right = 100000*10000
	while left <= right:
		middle = ( left+right )//2
		truckCnt = i = loadings = 0
		while i < n:
			loadings += w[i]
			if middle < loadings:
				truckCnt += 1
				if k < truckCnt+1:
					break
				loadings = w[i]
			i += 1

		if truckCnt+1 <= k:
			minP = middle
		
		if k < truckCnt+1:
			left = middle + 1
		else:
			right = middle - 1

print( minP )