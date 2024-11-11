n=int(input())
for i in range(n):
    a,b,c=input().split()
    a,b,c=int(a),int(b),int(c)
    cost=0
    cb,cc=input().split()
    cb,cc=int(cb),int(cc)
    if cb>cc:
        x=min(a//2,b)
        cost=x*cb
        if a-2*x>1:
            t=min((a-2*x)//2,c)
            cost+=t*cc
    elif cb<cc:
        x=min(a//2,c)
        cost=x*cc
        if a-2*x>1:
            t=min((a-2*x)//2,b)
            cost+=t*cb
    else:
        x=min(a//2,c+b)
        cost=x*cb
    print(cost)
