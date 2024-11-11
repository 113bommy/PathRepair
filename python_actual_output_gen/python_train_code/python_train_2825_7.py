n=int(input())
a=list(map(int,input().split()))
val=a[0]
b=[]
b.append(val)
c=[]
c.append(1)
for i in range(1,len(a)):
    if(a[i]<=val//2):
        b.append(a[i])
        
majority=sum(a)//2
if(val>majority):
    print(1)
    print(1)
elif(sum(b)>majority):
    print(len(b))
    for i in range(1,len(a)):
        if(a[i]<=val//2):
            c.append(i+1)
    print(c)
else:
    print(0)
        
        
