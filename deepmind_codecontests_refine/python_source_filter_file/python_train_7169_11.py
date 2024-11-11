for _ in[0]*int(input()):
 a,b,c,d,e,f,g,h=map(float,input().split())
 print(['NO','YES'][abs((a-c)*(f-h)-(e-g)*(b-d))<1e-9])
