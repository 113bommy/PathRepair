def merge( tS, left, mid, right ):
	global cnt
	n1 = mid - left;
	n2 = right - mid;
	tL = tS[ left : mid ];
	tR = tS[ mid : right ];	
	tL.append( 1000000001 )
	tR.append( 1000000001 )
	i = j = 0
	for k in range( left, right ):
		cnt += 1
		if tL[i] <= tR[j]:
			tS[k] = tL[i]
			i += 1
		else:
			tS[k] = tR[j]
			j += 1


def mergeSort( tS, left, right ):
	if left+1 < right:
		mid = ( left+right )//2
		mergeSort( tS, left, mid )
		mergeSort( tS, mid, right )
		merge( tS, left, mid, right )

n = int( input() )
arrS = [ int( val ) for val in input().split( ' ' ) ]
cnt = 0
mergeSort( arrS, 0, n )
print( " ".join( map( str, arrS ) ) )
print( cnt )