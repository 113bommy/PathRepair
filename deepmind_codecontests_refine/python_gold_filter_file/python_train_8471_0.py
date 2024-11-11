pri=pow(10,9)+7
p=pri
fac=[1 for i in range((10**6)+1)]
for i in range(2,len(fac)):
    fac[i]=(fac[i-1]*(i%pri))%pri
def modi(x):
    return (pow(x,p-2,p))%p;
    
def ncr(n,r):
    x=(fac[n]*((modi(fac[r])%p)*(modi(fac[n-r])%p))%p)%p
    return x;


n,m=map(int,input().split())
z=list(map(int,input().split()))
z.sort()
ans=[]
for i in range(len(z)):
    if(i==0):
        ans.append(z[0]-1)
    else:
        ans.append(z[i]-z[i-1]-1)
ans.append(n-z[-1])


temp=[]
for i in range(len(ans)):
    if(i==0 or i==len(ans)-1):
        temp.append(1)
    else:
        temp.append(pow(2,max(0,ans[i]-1),pri))

seats=n-m
count=1

for i in range(len(ans)):
    count=count*ncr(seats,ans[i])
    
    seats-=ans[i]
    count%=pri
for i in range(len(temp)):
    count=count*temp[i]
    count%=pri
print(count)
    
    
    
