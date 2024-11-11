import sys
e=iter(sys.stdin)
for a,b in zip(e,e):
 a,b,h=a.split(),b.split(),0
 for s,t in zip(a,b):h+=s==t
 print(h,4-len(set(a)-set(b))-h)
