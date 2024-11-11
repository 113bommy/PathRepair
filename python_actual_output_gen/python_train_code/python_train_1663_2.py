t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = [0] * (n + 2)
    c = 1
    d = a[0]
    ans = [a[0]]
    b[a[0]] = 1
    for i in range(1, len(a)):
        if a[i] == ans[i - 1]:
            while b[c] != 0:
                c += 1
            if c > a[i]:
                ans = -1
                break
            else:
                b[c] = 1
                ans.append(c)
        else:
            ans.append(a[i])
            b[a[i]] = 1
    if ans == -1:
        print(ans)
    else:
        print(*ans)
    
    
