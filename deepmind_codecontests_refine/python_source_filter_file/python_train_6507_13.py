#!/usr/bin/env python

import math

def main( ):
    lines = list( )

    while True:
        try: l = input( )
        except EOFError: break

        lines.append( l )

    maxLen = max( [ len( l ) for l in lines ] )
    alignLeft = True

    print( '*' * ( maxLen + 2 ) )
    for l in lines:
        spaces = maxLen - len( l )
        if spaces % 2:
            spacesLeft, spacesRight = spaces // 2 + 1, spaces // 2
            if not alignLeft:
                spacesLeft, spacesRight = spacesRight, spacesLeft
            alignLeft = not alignLeft
        else:
            spacesLeft = spacesRight = spaces // 2

        print( '*', end = '' )
        print( ' ' * spacesLeft , end = '' )
        print( l, end ='' )
        print( ' ' * spacesRight , end = '' )
        print( '*' )
    print( '*' * ( maxLen + 2 ) )



if __name__ == '__main__':
    main( )

