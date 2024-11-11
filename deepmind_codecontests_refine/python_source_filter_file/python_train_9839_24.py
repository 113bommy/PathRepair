t=int(input())
for r in range(t):
    n=int(input())
    sum=n*(n+1)/2
    a=1
    while (n>=a):            
        sum-=2*a         
        a*=2
    print(int(sum))
        