import sys
input=sys.stdin.readline
n=int(input())
a=[]
for i in range(n):
    e,b,c,d=map(int,input().split())
    a.append((e,b,c,d))
b=[1 for i in range(n)]
for i in range(n):
    for j in range(i+1,n):
        if a[i][0]>a[j][0] and a[i][1]>a[j][1] and a[i][2]>a[j][2]:
            b[j]=0
        if a[i][0]<a[j][0] and a[i][1]<a[j][1] and a[i][2]<a[j][2]:
            b[i]=0
an=1000
ann=0
for i in range(n):
    if b[i]:
        if an>a[i][3]:
            an=a[i][3]
            ann=i+1
print(ann)