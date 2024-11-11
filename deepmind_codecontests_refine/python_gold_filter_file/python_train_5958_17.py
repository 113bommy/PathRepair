for _ in range(int(input())):
    n,g,b = map(int,input().split())
    a = (n+1)//2
    tot = (a//g)*(g+b)
    if(a%g==0):
        tot-=b
    else:
        tot+=a%g
    print(max(n,tot))