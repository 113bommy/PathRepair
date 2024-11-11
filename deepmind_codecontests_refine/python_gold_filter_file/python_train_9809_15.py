T = int(input())
for i in range(T):
    n, x = map(int, input().split())
    s = str(input())
    l = [0]*n
    l[0] = 1 - 2*int(s[0])
    for j in range(1, n):
        if s[j] == "0":
            l[j] = l[j-1] + 1
        else:
            l[j] = l[j-1] - 1
    tmp = l[-1]
    ans = 0
    if x == 0:
        ans = 1
    if tmp != 0:
        for j in range(n):
            if (x - l[j]) % tmp == 0 and (x - l[j]) * tmp >= 0:
                ans += 1
        print(ans)
    else:
        flag = True
        for j in range(n):
            if x - l[j] == 0:
                flag = False
                print(-1)
                break
        if flag:
            print(ans)