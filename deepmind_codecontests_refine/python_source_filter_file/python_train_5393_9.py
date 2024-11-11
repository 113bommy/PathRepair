import fractions
a,b,c,d=map(int,input().split())
a=a-1
l=c*d/fractions.gcd(c,d)
B=b-((b//c)+(b//d)-(b//l))
A=a-((a//c)+(a//d)-(a//l))
print(int(B-A))