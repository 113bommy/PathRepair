import sys
n,k=map(int, sys.stdin.readline().split())
s=set()
ctr=0
for i in range(1,1000001):
    s.add(n%i)
    if len(s)!=i:
        print("No")
        ctr+=1
        break
if ctr==0:
    print("Yes")
        