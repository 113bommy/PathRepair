import fractions

A,B,C,D=map(int,input().split())
c=B//C-(A-1)//C 
d=B//D-(A-1)//D 
l=C*D//fractions.gcd(C,D)
cd=B//l-(A-1)//l
print(int(B-(A-1)-c-d+cd))
