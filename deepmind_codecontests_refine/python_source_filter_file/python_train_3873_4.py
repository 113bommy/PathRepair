def solve(a, b):
    size = len(a)
    answer = []
    for i in range(size):
        if a[i] != b[i]:
            for j in range(i + 1, size):
                if a[j] == a[i]:
                    answer.append([i + 1, j + 1])
                    b[i], a[j] = a[j], b[i]
                    break
                elif b[j] == a[i]:
                    answer.append([j + 1, j + 1])
                    answer.append([i + 1, j + 1])
                    b[j], a[j] = a[j], b[j]
                    b[i], a[j] = a[j], b[i]
                    break
    return answer


q = int(input())
for _ in range(q):
    n = int(input())
    s = list(input())
    t = list(input())
    char_shop = [0] * 26
    for i in range(n):
        char_shop[ord(s[i]) - 97] += 1
        char_shop[ord(t[i]) - 97] += 1
    fail = False
    for c in char_shop:
        if c % 2 != 0:
            fail = True
            break
    if fail:
        print('No')
        continue
    print('Yes')
    res = solve(s, t)
    print(len(res))
    for r in res:
        print(' '.join(map(str, r)))
