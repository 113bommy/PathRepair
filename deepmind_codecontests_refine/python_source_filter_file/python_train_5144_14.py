# cook your dish here
n,m=map(int,input().split())
z=0
s=0
k=-1
x=list(map(int,input().split()))
x.sort()

for i in range(0,len(x)):
    if(x[i]>0):
        
        break
    else:
        if z<=m:
            s=s+(0-x[i])
            z=z+1
        else:
            break
if k==0:
    print(0)
else:
    print(s)
        
