A,B=map(int,input().split())

import fractions
print(A*B//fractions.gcd(A,B))