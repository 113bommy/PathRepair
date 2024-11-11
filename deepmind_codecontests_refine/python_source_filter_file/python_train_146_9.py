n = int( input() )
w = list( map( int, input().split() ) )

w1, w2 = 0, 0

w.sort( reverse = True )

for num in w: 
    if ( w1 <= w2 ): 
        w1 += num
    else: 
        w2 += num
         
print ( "YES" ) if ( w1 == w2 ) else ( "NO" )