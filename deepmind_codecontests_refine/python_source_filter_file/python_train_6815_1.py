def solve(k, a, b):
    prefix = [0]
    for e in k:
        d = ord(e) - ord('0')
        prefix.append((prefix[-1] * 10 + d) % a)
    suffix = [0]
    p10 = 1
    for e in reversed(k):
        d = ord(e) - ord('0')
        suffix.append((suffix[-1] + p10 * d) % b)
        p10 = p10 * 10 % b
    n = len(k)
    for i in range(n - 1):
        if k[i + 1] != "0" and prefix[i + 1] == 0 and suffix[n - i] == 0:
            return i + 1


k = input()
a, b = map(int, input().split())
res = solve(k, a, b)
if res is None:
    print("NO")
else:
    print("YES")
    print(k[:res])
    print(k[res:])