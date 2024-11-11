# #
# #   Don't take it so seriously.
# #   Life's transient.
# #

t = int(input())
for test in range(t):
    n = int(input())
    a, b, c = [int(e) for e in input().split()]
    bob = input()
    a1, b1, c1 = 0, 0, 0
    for i in bob:
        if i == 'R':
            a1 += 1
        elif i == 'P':
            b1 += 1
        else:
            c1 += 1

    w = min(a, b1) + min(b, c1) + min(c, a1)
    if 2 * w < n:
        print("NO")
    else:
        print("YES")
        ans = ""
        for i in bob:
            if i == 'R':
                if b > 0:
                    ans += 'P'
                    b -= 1
                else:
                    ans += '?'
            elif i == 'P':
                if c > 0:
                    ans += 'S'
                    c -= 1
                else:
                    ans += '?'
            else:
                if a > 0:
                    ans += 'R'
                    a -= 1
                else:
                    ans += '?'

        ans = [e for e in ans]
        # print(ans)
        for i in range(len(ans)):
            if ans[i] == '?':
                if a > 0:
                    ans[i] = 'R'
                    a -= 1
                elif b > 0:
                    ans[i] = 'P'
                    b -= 1
                else:
                    ans[i] = 'S'
                    c -= 1
        print("".join(e for e in ans))
