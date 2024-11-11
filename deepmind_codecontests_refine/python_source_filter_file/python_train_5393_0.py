A,B,C,D=map(int, input().split())
f=C
g=D
while f%g!=0:
  f,g=[g, f%g]
l=C*D//g
m=B//l
n=A//l
print(B-(B//C)-(B//D)+m-(A-1-((A-1)//C)-((A-1)//D)+n))