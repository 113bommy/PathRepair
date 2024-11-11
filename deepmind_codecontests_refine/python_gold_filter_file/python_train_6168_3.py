t = int(input())
ans = []
for _ in range(t):
    n ,k=map(int, input().split())
    s=input()
    s=sorted(s)
    if k ==1:
        ans.append(''.join(s))
        continue
    if n == k:
        ans.append(s[k-1])
        continue
    if s[k-1] !=s[0]:
        ans.append(s[k-1])
        continue
    else:
        if len(set(s[k:])) > 1:
            ans.append(s[0] + ''.join(s[k:]))
            continue
        else:
            r = n - k
            r = (n-k)//k + (1 if (n-k)%k else 0)
            ans.append(s[0] + r*s[k])
for aa in ans:
    print(aa)
