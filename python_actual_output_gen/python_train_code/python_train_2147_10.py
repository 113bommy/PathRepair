N,M=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(N)]

AB_s=sorted(AB)

ans=0
cnt=0
for a,b in AB_s:
    ans+=a*b
    cnt+=b
    if cnt>M:
        ans-=a*(cnt-M)
        print(ans)
        exit()