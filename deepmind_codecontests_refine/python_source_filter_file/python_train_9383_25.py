import sys
input = sys.stdin.readline
for _ in range(1):
    n,k,m = map(int,input().split())
    l = list(map(int,input().split()))
    l.sort()
    som = sum(l)
    rem = m//k
    rem_dash = m%k
    ans = (som+(min(n*k,(rem*k)+rem_dash)))/n
    cnt = n
    for i in range(n-1):
        m -= 1
        som -= l[i]
        cnt -= 1
        rem = m // k
        rem_dash = m % k
        ans = max((som + (min(cnt * k, (rem * k) + rem_dash))) / cnt,ans)

    print(ans)