from collections import Counter
import sys
h,w=map(int,input().split())
a=list(sys.stdin.read())
c=Counter(a)
c["\n"]=0
n1=0
n2=0
if h*w%2:
  n1=1
if h%2:
  n2+=w//2
if w%2:
  n2+=h//2
n4=h//2+w//2
n1r,n2r,n4r=0,0,0
for i in c.values():
  n1r += i%2
  n2r += (i//2)%2
  n4r += i//4
if n1==n1r and n4r>=n4:
  print("Yes")
else:
  print("No")