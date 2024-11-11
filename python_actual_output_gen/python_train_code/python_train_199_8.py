t=int(input())

while t:
    n=int(input())
    m=int((n-1)/2)
    ans=(8/6)*m*(m+1)*(2*m+1)
    print(int(ans))
    
    t-=1