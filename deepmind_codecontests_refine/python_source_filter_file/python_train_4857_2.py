n = int(input())
s = input()
t = input()

if sorted(s) != sorted(t):
    print(-1)
else:
    res = []
    for i in range(n):
        k = 0
        while(s[k] != t[i]):
            k += 1
        res += [k + 1, n - 1, 0]
        s = ''.join(reversed(s[:k])) + s[k + 1:] + s[k]
#         print(s)
    print(len(res))
    print(*res)

            