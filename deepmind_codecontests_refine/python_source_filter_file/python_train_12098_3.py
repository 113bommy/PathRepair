t = int(input())
while t:
    t -= 1
    n = int(input())
    ans = []
    i = 0
    while i*i <= n:
        ans.append(i)
        if i:
            ans.append(n//i)
        i += 1
    ans = list(set(ans))
    ans.sort()
    print(len(ans))
    print(ans)
