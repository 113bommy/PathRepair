n=int(input())
a=list(map(int,input().split(' ')))
print(n+1)
print(1,n,10**6)
for i in range(n):
    a[i]=a[i]+10**6
for i in range(n):
    k=a[i]-i
    print(2,i+1,k)

    
    
    
