A,B = map(int,input().split())

import fractions
C = fractions.gcd(A,B)
print(A*B/C)