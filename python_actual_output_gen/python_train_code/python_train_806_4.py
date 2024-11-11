a, b, c, d = [int(x) for x in input().split()]
a, b, c  = sorted([a, b, c])
print( max(0, (d - a + b)) + max(0,( d - c + b))) 
