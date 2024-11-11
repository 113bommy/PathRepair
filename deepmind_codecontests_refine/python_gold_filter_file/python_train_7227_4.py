import math

x,k=map(int,input().split())
a=[0]*x

for i in range(k):
    c=list(map(int,input().split()))
    if(len(c)==2):
        a[c[1]]=1
    else:
        a[c[1]] = 1
        a[c[2]] = 1

max=0
min=0

for i in range(x):
    if a[i]==0:
        max+=1
max-=1
min=max
#print(a)
i=1

while i<(x-1):
    if a[i]==0 and a[i+1]==0:
        min-=1
        i+=1
    i+=1

print(min,max)


