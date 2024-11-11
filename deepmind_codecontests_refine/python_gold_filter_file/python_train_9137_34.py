from collections import Counter

n, p = map(int, input().split())
s = input()

if p == 2 or p == 5:
    ans = 0
    for i, e in enumerate(s, 1):
        if int(e) % p == 0:
            ans += i

    print(ans)

else:
    li = [0]
    for i, e in enumerate(s[::-1], 1):
        li.append((li[-1] + int(e) * pow(10, i, p)) % p)

    c = Counter(li)
    ans = 0
    for v in c.values():
        ans += v * (v - 1) // 2

    print(ans)
