from fractions import gcd
A,B,C,D=map(int,input().split())
A-=1
S=B-B//C-B//D+B//((C*D)//gcd(C,D))
T=A-A//C-A//D+A//((C*D)//gcd(C,D))
print(S-T)