from sys import stdin
import sys
n=int(stdin.readline().strip())
s=stdin.readline().strip()
g=0;r=0;b=0;
for i in s:
    if i=='R':
        r+=1
    elif i=='G':
        g+=1
    else:
        b+=1
if r==0 and g==0:
    print("B")
    sys.exit()
if b==0 and r==0:
    print("G")
    sys.exit()
if b==0 and g==0:
    print("R")
    sys.exit()
if (b>0 and r>0 and g>0) or (b>1 and r>1) or( b>1 and g>1) or (r>1 and g>1):
    print("RGB")
    sys.exit()
if b>1 and (r==1 or g==1):
    print("RG")
    sys.exit()
if r>1 and (b==1 or g==1):
    print("BG")
    sys.exit()
if g>1 and (r==1 or b==1):
    print("BR")
    sys.exit()
if r==1 and g==1:
    print("B")
    sys.exit()
if g==1 and b==1:
    print("R")
    sys.exit()
if r==1 and b==1:
    print("G")
    sys.exit()
