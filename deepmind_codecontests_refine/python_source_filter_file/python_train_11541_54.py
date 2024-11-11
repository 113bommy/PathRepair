from fractions import gcd
a,b,c=map(int,input().split())
print("NO"if c%gcd(a,b)!=0　else"YES")