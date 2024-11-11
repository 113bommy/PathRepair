for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    n = len(a)
    groups = 0
    s2 = False
    ind = 0
    for i in range(1, n):
        if a[i-1] != a[i]:
            groups += 1
        else:
            s2 = True
            ind = i - 1
    if a[-1] != a[0]:
        groups += 1
    else:
        if not s2:
            ind = 0
            s2 = True
    if groups == 0:
        groups = 1
    # print("g", groups)
    # print(s2, ind)
    if groups == 1:
        print(1)
        print("1 " * n)
    else:
        if groups % 2 == 1:
            if s2:
                a[ind] = -1
                groups += 1
        if groups % 2 == 0:
            t = 0
            print(2)
            print("1", end=' ')
            for i in range(1, n):
                if a[i] == a[i-1]:
                    print(t+1, end=" ")
                else:
                    t = (t + 1) % 2
                    print(t+1, end=" ")
            print()
        else:
            ans = []
            print(3)
            t = 0
            ans.append("1 ")
            # print("1", end=' ')
            for i in range(1, n):
                if a[i] == a[i - 1]:
                    # print(t + 1, end=" ")
                    ans.append(str(t+1) + " ")
                else:
                    t = (t + 1) % 2
                    # print(t + 1, end=" ")
                    ans.append(str(t + 1) + " ")
            # ans[-1] = "3 "
            # print("aa", ans)
            for i in range(n):
                if a[i] != a[(i+1)%n] and ans[i] == ans[(i+1)%n]:
                    ans[i] = "3 "
            print("".join(ans))