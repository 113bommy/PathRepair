n = int( input() )
a = list( map( int, input().split() ) )

tmp = 0
for data in a:
    tmp = tmp ^ data

if data == 0:
    print('Yes')
else:
    print('No')