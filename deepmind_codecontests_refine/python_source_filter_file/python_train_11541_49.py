import math
a,b,c = map(int, input().split())
r = math.gcd(a,b)
if c % r == 0:
    print('YES')
else:
    print('NO')
    
