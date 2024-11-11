for _ in range(int(input())):
    n,g,b = map(int,input().split())
    a = (n+1)//2
    tot = (a//g)*(g+b)
    if(tot%g==0):
        tot-=b
    else:
        tot+=tot%g
    print(max(n,tot))