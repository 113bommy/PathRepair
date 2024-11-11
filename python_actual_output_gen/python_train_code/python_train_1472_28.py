n=int(input())
if n%2==1:print(0)
else:
    ans=0
    for i in range(1,19):
        ans+=n//(10**i)
    print(ans)