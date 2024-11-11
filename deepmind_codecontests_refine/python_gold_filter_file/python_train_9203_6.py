n=int(input())
for x in range(4):
    a,b,c,d=map(int,input().split())
    k1=min(a,b)
    k2=min(c,d)
    ans=-1
    con=0
    while True:
        if n-k1>=0:
            if n-k1>=k2:
                ans=[x+1,k1,n-k1]
                con=1
                break
            else:
                k1+=1
        else:
            break
    if con:
        print(*ans)
        break
else:
    print(ans)