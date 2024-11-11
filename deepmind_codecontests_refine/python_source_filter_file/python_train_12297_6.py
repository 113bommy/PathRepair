q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    n=r-l+1
    if(l%2==0 and r%2==0):
        ne=(r-l)//2+1
        no=n-ne
        sum1=ne*(l+r)//2-no*(l+r)//2
    elif(l%2==0 and r%2!=0):
        ne=(r-1-l)//2+1
        no=n-ne
        sum1=ne*(l+r-1)//2-no*(l+1+r)//2
    elif(l%2!=0 and r%2==0):
        ne=(r-l+1)//2+1
        no=n-ne
        sum1=ne*(l+1+r)//2-no*(l+r-1)//2
    else:
        ne=(r-1-(l+1))//2+1
        no=n-ne
        sum1=ne*(l+r)//2-no*(l+r)//2    
    print(sum1)    
