n = int( input() )

d = {}
for i in range( n ):
    name1, _, name2 = input().lower().split( ' ' )
    try: d[name2]
    except: d[name2] = []
    d[name2].append( name1 )

def recurs( name, depth = 1 ):
    # print( 'name = %s' % name )
    try:
        for child in d[name]:
            yield from recurs( child, depth + 1 )
    except:
        # print( 'yielding %i' % depth )
        yield depth

print( max( recurs( 'polycarp' ) ) )
