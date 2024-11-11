n,p=map(int, input().split())
ans=1
m=int(pow(p,1/n))+1
if n==1:
    print(p)
else:
    m=int(pow(p,1/n))+1
    i=2
    c=0
    while(i<=p and i<=m):
        print('i,p=',i,p)
        if p % i == 0:
            p=p/i
            c=c+1
            if p % i != 0:
                #print('i**(c//n)=',i**(c//n))
                ans = ans * ( i**(c//n) )
                i=i+1
                c=0
        else:
            i=i+1
    print(ans)
