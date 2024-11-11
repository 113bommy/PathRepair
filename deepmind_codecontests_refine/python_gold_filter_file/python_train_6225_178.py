A,B = map(int,input().split())
import fractions
d = fractions.gcd(A,B)
print(A*B//d)