import fractions
A,B,C,D=map(int,input().split())
L=C*D//(fractions.gcd(C,D))
print(int(B-A+1-(B//C-((A-1)//C))-(B//D-((A-1)//D))+(B//L-((A-1)//L))))