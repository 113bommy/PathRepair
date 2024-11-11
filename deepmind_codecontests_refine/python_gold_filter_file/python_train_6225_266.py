a,b=map(int,input().split())
import fractions as f
print(a*b//f.gcd(a,b))