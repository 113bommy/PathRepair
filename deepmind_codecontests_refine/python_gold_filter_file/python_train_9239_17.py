import math
n,b,s=map(int,input().split())
l=[0]+list(map(int,input().split()))
x,y=map(int,input().split())
c=1
t=l[2]/b  + math.pow ((x-l[2])**2+y**2,0.5)/s
ans=2
w=0
if (y!=0):
 for i in l[2:]:
    c=c+1
    t1=i/b  + math.pow ((x-i)**2+y**2,0.5)/s
    if i>x :
        if t1 <t :
            t=t1
            ans=c
        #print(t1,t,c,ans)   
        break
    else :
        if t1 <t :
            t=t1
            ans=c
        #print(t1,t,c,ans) 
else :
 if (s> b):
   exit (print("2"))
 for i in l[2:]:
     c=c+1
     if (i<=x):
         ans=c
     else:
         break;
print(ans)        

