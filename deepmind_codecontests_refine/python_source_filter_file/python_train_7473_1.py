def main():
    n=int(input())
    a=list(map(int,input().split()))
    mod=10**9+7
    if n==1:
        print(2*a[0]%mod)
        return
    a.sort(key=lambda x:-x)
    mod=10**9+7
    ans=sum([a[i]*(i+2))%mod for i in range(n)])
    ans=ans*pow(2,n,mod)*pow(2,n-2,mod)%mod
    print(ans)

main()