import sys
for e in sys.stdin:
 a,b,c,d,e,f=map(int,e.split())
 y=(c*d-a*f)/(b*d-a*e)
 print(f'{(c-b*y)/a} {y}')
