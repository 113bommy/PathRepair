import sys
[n,d,h]=[int(i) for i in input().split()];
if n==2:
    print(1,2);
    sys.exit(0);
if (d==1) or (d>2*h):
    print(-1);
    sys.exit(0);
for i in range(1,h+1):
    print(i,i+1);
if(d+1>h+1):
    print(1,h+2);
for i in range(h+3,d+2):
    print(i-1,i);
for i in range(d+2,n+1):
    print(h,i);
