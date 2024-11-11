t = int(input())
for _ in range(t):
    b,p,f = map(int,input().split())
    h,c = map(int,input().split())
    count = b//2
    ans = 0
    if c>h:
        ans+=min(count,f)*c
        count -= min(count,f)
        ans += min(count,p)*h
        print(ans)
    else:
        ans+=min(count,p)*h
        count -= min(count,p)
        ans += min(count,f)*c
        print(ans)
