from sys import *
input=stdin.readline
n=int(input())
l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
l.sort()
f=0
x,y=-1,-1
for i in range(n):
    if(l[i][0]>x):
        x=l[i][1]
    elif(l[i][0]>y):
        y=l[i][1]
    else:
        f=1
        break
if(f==1):
    print("NO")
else:
    print("YES")
