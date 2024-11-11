import sys
input()
d=dict.fromkeys('AC WA TLE RE'.split(),0)
for ln in sys.stdin:
    d[ln.strip()]+=1
for k,v in d.items():
    print(k,'x',v)
