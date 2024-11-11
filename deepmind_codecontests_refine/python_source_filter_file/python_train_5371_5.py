from math import gcd
n = int( input( ) )
a = [int( i ) for i in input( ).split( )]
g = 0
count = 0
result = 0
for p in a :
    g = gcd( g , p )
    if p & 1 :
        count += 1
    else :
        result += ( count // 2 ) + 2 * ( count & 1 )
        count = 0
result += ( count // 2 ) * 2 * ( count & 1 )
print( "YES" )
if g == 1 :
    print( result )
else :
    print( 0 )