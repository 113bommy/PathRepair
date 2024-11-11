import sys
for a,b,c in map(lambda x:sorted(map(int,x.split())),sys.stdin):
 print(['NO','YES'][a*a+b*b==c*c])
