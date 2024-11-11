t = int(input())
for _ in range(t):
    n = int(input())
    sigh = {}
    ans = "YES"
    for k in range(n):
        s = input()
        for i in s:
            if i not in sigh:
                sigh[i] = 1
            else:
                sigh[i] += 1
    for j in sigh.values():
        if j % 2 == 1:
            ans = "NO"
            break
    print(ans)
