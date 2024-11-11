import bisect
def main():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    l=0
    r=n
    d = {}
    if sum(a)<k:
        print(n)
    else:
        while l!=r:
            i=(l+r)//2
            ta = a[i]
            if ta in d.values():
                flag = d[ta]
            elif ta>=k:flag=True
            else:
                flag = False
                na = a[:i]+a[i+1:]
                dp = [False for _ in range(k+1)]
                dp[0]=True
                for j in range(n-1):
                    for m in range(k,0,-1):
                        if m-na[j]>=0:
                            dp[m]=dp[m] or dp[m-na[j]]
                        if m != k and m>=k-ta and dp[m]:
                            flag = True
                            break
                    if flag:break
                d[ta] = flag
            
            if flag:
                r=i
            else:
                l=i+1
        print(l)

main()