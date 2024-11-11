
for _ in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    d = dict()
    mn_sub = 10**6
    for i in range(n):
        if s[i] not in d:
            d[s[i]] = i
        else:
            if i - d[s[i]] < mn_sub:
                mn_sub = i - d[s[i]] + 1 
                d[s[i]] = i
    if mn_sub == 10**6:
        print(-1)
    else:
        print(mn_sub)
    


