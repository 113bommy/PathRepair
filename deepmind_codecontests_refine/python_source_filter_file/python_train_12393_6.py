import sys
for c in sys.stdin:
    a,b=sorted(map(int,c.split()))
    if a=b==0:break
    print(a,b)