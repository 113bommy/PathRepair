t=int(input())
x=list(map(int,input().split()))
c=0
if (sum(x)>t):
    s=sum(x)
else:
    f=t//sum(x)
    if(t%sum(x)==0):
        s=sum(x)*max(1,(f-1))
    else:
        s=sum(x)*max(1,f)
    t=t-s
i=0
#print(t)
while(t>0):
    t=t-x[i]
    c+=1
    i+=1
 #   print(i,t)
print(c)
