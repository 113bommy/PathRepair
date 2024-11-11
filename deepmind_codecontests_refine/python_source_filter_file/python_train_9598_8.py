n,a,b=map(int,input().split())
ans=n-(a+b)
if ans>1:
    print((n-a)-(ans-1))
elif ans==1:
    print(n-a)
