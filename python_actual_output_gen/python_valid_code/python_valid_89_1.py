t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    if n%2==0:
        x=n//2 
    else:
        x=n//2+1 
    c=0
    i=n*k-x-1
    y=n*k-i
    sum=0
    while(c<k):
        sum+=a[i]
        i-=y 
        c+=1 
    print(sum)
        
        
        