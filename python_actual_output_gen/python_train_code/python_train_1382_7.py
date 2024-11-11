n,m=map(int,input().split())
ka=1
while(n>0 and m>0):
    if(n>m):
        n=n-2
        m=m+1
    else:
        m=m-2
        n=n+1
    if(n<1 or m<1):
        break
    ka+=1
print(ka)
