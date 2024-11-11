def isfet(i,k):
    return(k%i==0)

t=[]    
n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(len(a)):
    if(isfet(a[i],k)):
        t.append(a[i])
z=min(t)
print(k//z)
        
