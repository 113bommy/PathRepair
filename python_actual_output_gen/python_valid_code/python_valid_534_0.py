for i in range(int(input())):
    n = int(input())
    s = input()
    ans = ''
    d = {"B": "R", "R": "B"}
    for j in range(n):
        if s[j] != '?':
            ans += s[j]
        else:
            if j == 0:
                h = '.'
                o = 0
                for k in range(n):
                    if s[k] != '?':
                        h = s[k]
                        o = k
                        break
                if h == '.':
                    ans += 'B'
                else:
                    if 0 % 2 == 0:
                        ans += d[h]
                    else:
                        ans += h
            else:
                ans += d[ans[-1]]
    print(ans)
