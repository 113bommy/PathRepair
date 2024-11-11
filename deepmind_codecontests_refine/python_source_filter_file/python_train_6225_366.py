A, B = map(int, input().split())
from fraction import gcd
 
print(A * B // gcd(A, B))