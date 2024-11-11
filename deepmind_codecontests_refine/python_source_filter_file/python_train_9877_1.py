import sys
for x in sys.stdin:
 a,b,c,d,e,f,g,h=map(float,x.split());z=1e-9
 print(['NO','YES'][-z<(a-c)*(e-g)+(b-d)*(f-h)<z])
