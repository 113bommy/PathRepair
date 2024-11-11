for _ in range(int(input())):
    n= int(input())
    a= list(map(int,input().split()))
    for i in range(n):
        if (a[i]==1):
            ind=i
    i=0
    ans=False
    f=True 
    while(i!=n-1):
        if (a[ind]+1==a[(ind+1)%n]):
            ind=(ind+1)%n
        else:
            f=False
        i+=1    
    i=0
    ans = ans or f
    f=True
    while (i!=n-1):
        if (a[(ind-1+n)%n]==a[ind]+1):
            ind=(ind-1+n)%n
        else :
            f=False
        i+=1    
    ans = ans or f
    if (ans):
        print("YES")
    else:
        print("NO")