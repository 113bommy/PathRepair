a=int(input())
import math
def fact(x):
    ans=[]
    for i in range(1,int(math.sqrt(x))+1):
        
        if(x%i==0):
            if(i==x//i):
                ans.append(i)
            else:
                ans.append(x//i)
                ans.append(i)
    
    ans.sort()
    
    return ans;
for i in range(a):
    
    n,k=map(int,input().split())
    ans=n
    fac=fact(n)
    if(fac[1]==n):
        ans=2*n
        k=k-1
        fac[1]=2
    if(k==0):
        print(ans)
        continue;


    
    if(fac[1]==2):
        
        ans=ans+(k*2)
        print(ans)
        continue;
    else:
        ans=ans+fac[1]
        k=k-1
        if(k==0):
            print(ans)
            continue;
        else:
            k=k
            ans=ans+(k*2)
            print(ans)
            continue;
            
        




    
