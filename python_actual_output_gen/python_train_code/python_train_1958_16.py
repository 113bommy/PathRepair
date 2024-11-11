def sol( bun, a, amoney, b, bmoney):
    ans=int(0)
    if bun%2==1:
        bun-=1
    if bun>=a*2:
        ans+=a*amoney;bun-=a*2
    else:
        ans+=(bun*amoney)/2;bun=0
    if bun>=b*2:
        ans+=b*bmoney;bun-=b*2
    else:
        ans+=bun*bmoney/2;
    return int(ans)
test=int(input())
for i in range(test):
    bun,beef,chicken=map(int,input().split())
    moneyOfBeef,moneyOfChicken=map(int,input().split())
    print(min(sol(bun,beef,moneyOfBeef,chicken,moneyOfChicken),sol(bun,chicken, moneyOfChicken , beef , moneyOfBeef)))
