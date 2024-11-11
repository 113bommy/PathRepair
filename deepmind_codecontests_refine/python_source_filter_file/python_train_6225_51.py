import fraction
a,b=map(int,input().split())
print((a*b)//fraction.gcd(a,b))