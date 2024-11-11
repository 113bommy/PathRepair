import fractions
a,b,c,d=map(int, input().split())
cdlcm= a*b//fractions.gcd(a,b)
a-=1
tc = b//c-a//c
td = b//d-a//d
tlcm = b//cdlcm-a//cdlcm
print(b-a-tc-td+tlcm)