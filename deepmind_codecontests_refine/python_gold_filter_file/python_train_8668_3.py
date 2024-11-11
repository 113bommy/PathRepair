for _ in range(int(input())):
    x,y,k=map(int,input().split())
    sticksreq=(y*k)+k-1
    onetrade=x-1
    if sticksreq%onetrade:
        ans=sticksreq//onetrade+k+1
    else:
        ans=sticksreq//onetrade+k
    print(ans)