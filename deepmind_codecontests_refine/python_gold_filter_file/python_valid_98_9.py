for _ in range(int(input())):
    n = int(input())
    s = input()
    fl = 0
    if (n == 2):
        if (s.count('a') == s.count('b')):
            print(1, 2)
        else:
            print(-1, -1)
    else:
        for i in range(2, n, 2):
            for j in range(n - i + 1):
                if (s[j: j + i].count('a') == s[j: j + i].count('b')):
                    print(j + 1, j + i)
                    fl = 1
                    break
            if fl:
                break
        else:
            print(-1, -1)