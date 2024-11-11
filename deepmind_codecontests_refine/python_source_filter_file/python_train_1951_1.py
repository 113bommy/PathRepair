import math
l=input().split()
x=int(l[0])
y=int(l[1])
if x<y and x>=3:
    print(">")
if y<x and y>=3:
    print("<")
if x==y:
    print("=")
if x==2 and y==3:
    print("<")
if x==3 and x==2:
    print(">")
if x==2 and y==4 or x==4 and y==2:
    print("=")
if x==1 and y==2:
    print("<")
if x==2 and y==1:
    print(">")
if x==1 and y>=3:
    print("<")
if x>=3 and y==1:
    print(">")
if x==2 and y>=5:
    print(">")
if y==2 and x>=5:
    print("<")
    