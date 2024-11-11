for _ in range(int(input())):
    n, k = map(int, input().split())
    s = str(n)
    m = int(len(s) * '1')
    for i in range(1, 10):
        if i * m >= n:
            ans = i * m
            break
    if k == 2:
        for i in range(1, 9):
            for j in range(i + 1, 10):
                flag = 0
                for x in range(len(s)):
                    if int(s[x]) < j:
                        if int(s[x]) < i:
                            ans = min(ans, int(s[:x] + str(i) * (len(s) - x)))
                        ans = min(ans, int(s[:x] + str(j) + str(i) * (len(s) - x - 1)))
                    if s[x] != str(i) and s[x] != str(j):
                        flag = 1
                        break
                if not flag:
                    ans = n
    print(ans)
