t = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    a = [x - 1 for x in list(map(int, input().split()))]
    b = [x - 1 for x in list(map(int, input().split()))]
    mp = {}
    cnt=m
    pos=-1
    for i in range(n):
        mp[a[i]]=i
    for i in range(m):
        if(mp[b[i]]>pos):
            cnt+=((mp[b[i]]-i)*2)
        pos = mp[b[i]]
    print(cnt)
            
    