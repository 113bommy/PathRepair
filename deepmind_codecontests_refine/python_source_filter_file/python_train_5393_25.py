import fractions
a,b,c,d=map(int,input().split())
a-=1
y=c*d/fractions.gcd(c,d)

p=a-((a//c)+(a//d)-(a//y))

q=b-((b//c)+(b//d)-(b//y))

print(int(q-p))