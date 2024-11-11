import sys
e=iter(map(lambda a:a.split(),sys.stdin))
for a,b in zip(e,e):
 h=0;for s,t in zip(a,b):h+=s==t
 print(h,4-len(set(a)-set(b))-h)
