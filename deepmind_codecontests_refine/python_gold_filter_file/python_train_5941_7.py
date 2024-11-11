while True:
    n = int( input() )
    if n==0:
        break
    a=list(map(int, input().split()))
    m=sum(a)/n
    s=0
    for i in a:
        s+=(i-m)**2
    print( ( s/n)**0.5 )