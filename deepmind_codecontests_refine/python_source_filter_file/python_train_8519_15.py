N=int(input())
arr=list(map(int,input().split()))
min_,max_=min(arr),max(arr)
ans=None

if max_-min_ > 1:
    ans=False
elif max_-min_ == 1:
    """
    A=max_
    y=len([a for a in arr if a==max_])
    x=N-y
    nc=A-x
    ans=(A-x)>0 and y >=2*(A-x)
    """
    
    y=len([a for a in arr if a==max_])
    x=N-y
    nc=max_-x
    ans=nc!=0 and y>=2*nc

else:
    ans=N>=2*min_ or min_+1==N

print("Yes" if ans else "No")
