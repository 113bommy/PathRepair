a,b=map(int,input().split())
import fractions as f
print(int(a*b//f.gcd(a,b)))
