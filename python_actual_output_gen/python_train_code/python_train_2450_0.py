def hcfnaive(a,b): 
    if(b==0): 
        return a 
    else: 
        return hcfnaive(b,a%b) 
n,k=map(int,input().split())
a=input().split()
for i in range(n):
    a[i]=int(a[i])
gcd=a[0]    
for i in range(2,n):
    gcd=hcfnaive(gcd,a[i])
l=0
ans=[]
for i in range(k):
    ans.append(l%k)
    l+=gcd
ans=list(set(ans))    
ans.sort()
print(len(ans))
print(*ans)
