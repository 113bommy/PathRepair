import sys
e=iter(sys.stdin)
for a,b in zip(e,e):
 a,b=a.split(),b.split()
 for s,t in zip(a,b):h+=s==t
 print(h,4-len(set(a)-set(b))-h)
