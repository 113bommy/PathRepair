while True:
    n = int( input() )
    if n==0:
        break
    a=map(int, input().split())
    m=sum(a)
    s=0
    for i in a:
         s+=(i-m)**2
    print( ( s/n)**0.5 )