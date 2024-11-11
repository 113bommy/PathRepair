vertical = { 0: (1,1), 1: (1,2), 2: (1,3), 3: (1,3) }
horizontal = { 0: (3,1), 1:(3,3) }
string = list(input())
hc, vc = 0,0
for s in string:
    if s=='0':
        print( *vertical[vc%4] )
        vc+=1
    else:
        print( *horizontal[hc%2] )
        hc+=1