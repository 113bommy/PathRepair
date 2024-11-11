n = int( input() )
a = list( map( int, input().split() ) )

p1, p2, p3 = [], [], []
for i in a:
    if i > 0:
        p2.append(i)
    elif i < 0:
        p1.append(i)
    else:
        p3.append(i)

if len(p2) == 0:
    p2.append(p1[-2])
    p2.append(p1[-1])
    del p1[-1], p1[-2]
if len(p1) == 0:
    p1.append(p2[-1])
    del p2[-1]

if len(p1) % 2 == 0:
    p3.append( p1[-1] )
    del p1[-1]

print( len(p1), end=' ' )
for i in p1:
    print( i, end= ' ' )
print()

print( len(p2), end=' ' )
for i in p2:
    print( i, end= ' ' )
print()

print( len(p3), end=' ' )
for i in p3:
    print( i, end= ' ' )
print()
