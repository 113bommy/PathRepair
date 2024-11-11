def customer(l,n):
    i=0
    count=0
    while i<n-1:
        if l[i]==0:
            l[i]=1
            count+=1
        i+=1
    if sum(l)==0:
        count+=1
    return count
        
        
            




t=int(input())
for _ in range(t):
    n=int(input())
    queries=list(map(int,input().split()))
    print(customer(queries,n))