#!/usr/bin/env python

import math

def dist( x1, y1, x2, y2 ):
    return math.sqrt( ( x2 - x1 ) ** 2 + ( y2 - y1 ) ** 2 )

def main( ):
    n, vb, vs = map( int, input( ).split( ) )
    stations = list( map( int, input( ).split( ) ) )
    xu, yu = map( int, input( ).split( ) )

    # -------------------------------------------------------------

    minIdx, minVal = None, None

    for i in range( len( stations ) ):
        if i == 0: continue

        t = stations[ i ] / vb + dist( stations[ i ], 0, xu, yu ) / vs

        if minIdx == None or t < minVal or ( t == minVal and dist( stations[ minIdx ], 0, xu, yu ) > dist( stations[ i ], 0, xu, yu ) ):
            minIdx = i
            minVal = t

    print( minIdx + 1)


if __name__ == '__main__':
    main( )

