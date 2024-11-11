import sys
n,x=map(int,input().split())
a=[int(x) for x in input().split()]
if len(a)<n:
    print(0)
    sys.exit()

for i in a:
    if i &x !=i and i & x in a:
        print(1)
        sys.exit()
s=set(i&x for i in  a)
if len(s)<n:
    print(2)
    sys.exit()

print(-1)
