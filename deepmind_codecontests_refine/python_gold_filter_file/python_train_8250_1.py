
for _ in range(int(input())):
    n = int(input())
    ss = input()
    sss = input()
    s1 = []
    s2 = []
    for j in ss:
        s1.append(int(j))
    for j in sss:
        s2.append(int(j))
    ans = []
    ans2 = []
    for i in range(len(s1) - 1):
        if s1[i] != s1[i + 1]:
            ans.append(i + 1)
    if s1[-1] == 1:
        ans.append(n)
    ans2 = []
    for i in range(len(s2) - 1):
        if s2[i] != s2[i + 1]:
            ans2.append(i + 1)
    if s2[-1] == 1:
        ans2.append(n)
    for i in range(len(ans2) - 1, -1, -1):
        ans.append(ans2[i])
    print(len(ans), end = ' ')
    print(*ans)