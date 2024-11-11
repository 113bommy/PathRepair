A, B = map(int, input().split())
from fractions import gcd
 
print(A * B // gcd(A, B)