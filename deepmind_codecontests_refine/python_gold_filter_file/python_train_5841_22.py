n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
v=[]
f=max(b[0],c[0])
l=min(b[0],c[0])
g=max(b[1],c[1])
k=min(b[1],c[1])
count=0
if a[0]<f and a[0]>l:
    count+=1
if a[1]<g and a[1]>k:
    count+=1
if count>0:
    print('NO')
else:
    print('YES')
