a,b = map(int,input().split())
import fractions
print((a*b)//fractions.gcd(a,b))