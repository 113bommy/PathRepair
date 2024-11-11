n=int(input())
s=list(input())
v=[]
for i in range(1,n):
    if s[i]==s[i-1]:
        del(v[-1])
        v.append(1)
        
    else:
        v.append(0)


if v[0]==0:
    ans=3
else:
    ans=6
for i in range(1,len(v)):
    if v[i-1]==0:
        ans*=2
    elif v[i]==1:
        ans*=3
    else:
        continue
    

mod = 1000000007

print(ans%mod)
        

        
    
