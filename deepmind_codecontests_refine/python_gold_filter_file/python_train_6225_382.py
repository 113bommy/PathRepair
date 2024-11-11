a,b=map(int,input().split())
import fractions as fr
print(int(a*b/fr.gcd(a,b)))