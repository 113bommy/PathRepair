
n=int(input())
l=[]
l=list(map(int,input().split()))

fr=[0]*1000005
a=[0]*1000005
b=[0]*1000005

for i in range(n):
    fr[l[i]]=fr[l[i]]+1;
    if a[l[i]]==0:
        a[l[i]]=i+1
    b[l[i]]=i+1;

max1=0
min1=10000005
x=int()
y=int()
for i in range(1000001):
    if fr[i]>max1:
        max1=fr[i]
        x=a[i]
        y=b[i]
        min1=y-x+1
    elif fr[i]==max1:
        x1=a[i]
        y1=b[i]
        if y1-x1+1<min1:
            min1=y-x+1
            x=x1
            y=y1
print(x,y,sep=' ')
