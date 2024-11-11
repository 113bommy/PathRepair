t=int(input())
while t>0:
    t-=1 
    n,m=map(int,input().split())
    s=n*(m//2)
    if m%2==1:
        s+=n//2
    if n%2==1:
        s+=1 
    print(s)