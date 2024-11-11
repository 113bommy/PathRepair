n=int(input())
a=list(map(int,input().split()))
a.sort()
b=sum(a)
print(a[n-1]*n-b)
    
