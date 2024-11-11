import fractions

A, B, C, D=map(int, input().split())
x=C*D//fractions.gcd(C, D)
p=B//C-(A-1)//C
q=B//D-(A-1)//D
r=B//x-(A-1)//x
print(int(B-(A-1)-(p+q-r)))