from collections import Counter

n = int(input())
s = Counter(map(int, input().split()))
n = 0

for q in s:
    s[q] -= 1

    for a in s:
        if s[a]:
            t = [a]
            s[a] -= 1
            b = q + a

            while s.get(b, 0):
                s[b] -= 1
                t.append(b)
                a, b = b, a + b

            n = max(n, len(t))

            for c in t:
                s[c] += 1
    s[q] += 1

print(n)
