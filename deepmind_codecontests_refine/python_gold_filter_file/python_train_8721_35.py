N,M = map(int, input().split())
A = sorted(list (map(int, input() .split() ) ) )

if A[N-M] >= sum(A)/M/4 :
	print( 'Yes' )

else :
	print( 'No' )