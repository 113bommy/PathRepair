t=int(input())
a=list(map(int,input().split()))
c=1
k=-1
for i in range(t-1):
    if(a[i]<=a[i+1]):
        c+=1
    else:
        if(c>k):
            k=c
        c=1
if(c>k):
    k=c
print(k)    
    
