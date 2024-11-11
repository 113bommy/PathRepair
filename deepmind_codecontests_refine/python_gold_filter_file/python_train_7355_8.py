import math
n,a,b=[int(n) for n in input().split()]
s=input()
c=a
d=b
arr=[]
l=0
for i in range(n):
    if(s[i]=="."):
        l=l+1
    if(s[i]=="*"):
        if(l>0):
            arr.append(l)
            l=0
if(l>0):
    arr.append(l)
for j in arr:
    if(j%2==0):
        c=c-min(j//2,c)
        d=d-min(j//2,d)
    else:
        if(c>d):
            c=c-min((j+1)//2,c)
            d=d-min(j//2,d)
        else:
            d=d-min((j+1)//2,d)
            c=c-min(j//2,c)
print((a+b)-(c+d))            
    

            
            
        
