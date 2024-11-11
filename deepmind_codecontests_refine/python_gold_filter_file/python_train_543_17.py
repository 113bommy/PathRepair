t=int(input())

while t:
    n=int(input())
    m=(n-1)/2
    ans=(8/6)*m*(m+1)*(2*m+1)
    print(round(ans))
    
    t-=1