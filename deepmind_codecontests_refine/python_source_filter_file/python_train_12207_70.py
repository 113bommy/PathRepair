t=int(input())
while t>0:
    n=int(input())
    if n%2==0:
        print(n/2)
    else:
        print((n-1)//2)
    t-=1