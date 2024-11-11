a,b=map(int,input().split())
import fractions
big=fractions.gcd(a,b)
print(a*b//big)