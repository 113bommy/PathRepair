import sys
  
for s in list(sys.stdin):
    a,b,e,c,d,f = list(map(float,s.split()))
    base = a*d-b*c
    x = e*d-b*f
    y = a*f-e*c
    print('%.3f %.3f' % (x/base,y/base))