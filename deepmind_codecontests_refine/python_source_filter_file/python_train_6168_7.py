t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = list(str(input()))
    s.sort()
    #print(s)
    if k == 1:
        print(''.join(s))
        continue
    if k == n:
        print(s[-1])
        continue
    if s[0] != s[k-1]:
        print(s[k-1])
        continue
    d = {}
    for i in range(k, n):
        if s[i] not in d:
            d[s[i]] = 1
        else:
            d[s[i]] += 1
    if len(d) == 1:
        v = list(d.values())
        q, r = divmod(v[0], k)
        if r == 0:
            ans = s[0]+s[-1]
        else:
            ans = s[0]+s[-1]*(q+1)
        print(ans)
    else:
        ans = [s[0]]
        for k, v in d.items():
            ans += [k]*v
        print(''.join(ans))
