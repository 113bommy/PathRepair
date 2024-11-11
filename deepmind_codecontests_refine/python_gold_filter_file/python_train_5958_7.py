import math
for _ in range(int(input())):
    n,g,b=map(int,input().split())
    target=math.ceil(n/2)
    gp=0
    bp=0
    isg=True
    ans=0
    # while n>0:
    #     if isg:
    #         gp+=min(n,g)
            
    #         ans+=min(n,g)
    #         n-=min(n,g)
    #     else:
    #         if gp>=target:
    #             bp+=min(n,b)
    #             ans+=min(n,b)
    #             n-=min(n,b)
    #         else:
    #             rem=n-(min(n,b))
    #             if rem+gp>=target:
                    
    #                 bp+=min(n,b)
    #                 ans+=min(n,b)
    #                 n-=min(n,b)
    #             else:
    #                 req=target-gp
    #                 b_can_take=max(n-req,0)
    #                 ans+=b 
    #                 bp+=b_can_take
    #                 n=n-b_can_take
    #     isg=not isg
    l=0
    r=1e10
    x=0
    while l<=r:
        mid=(l+r)//2
        rem=n-mid*(g+b)
        gp=mid*g 
        if gp+rem>=target and n-mid*(g+b)>=0:
            x=int(mid) 
            l=mid+1 
        else:
            r=mid-1
    rem=n-x*(g+b)
    ans+=x*(g+b)
    gp=x*g
    req=target-gp
    if req<=g:
        print(ans+rem)
    else:
        ans+=g 
        req-=g 
        rem-=g 
        #using last bp
        rem1=max(rem-req,0)
        ans+=b 
        rem-=rem1 
        y=rem//(g)
        ans+=max(y*(g+b)-b,0)
        rem-=y*g
        if rem>0 and y>0:
            ans+=b
        ans+=rem 
        print(ans)
                    
        