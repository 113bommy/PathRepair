n=int(input())
for i in range(n):
    l=input().split()
    l=list(map(int,l))
    n=l[0]
    a=l[1]
    b=l[2]
    if a/1 < b/2:
        cost=a*n
        
    else:
        mul=n//2
        mod=n%2
        cost=mul*b + mod*a
    
    print(cost)