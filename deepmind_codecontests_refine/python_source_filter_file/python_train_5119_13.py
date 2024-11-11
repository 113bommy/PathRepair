n, m = map(int, input().split())
s = list(map(int, input().split()))
sas = s.copy()
g = 0
ans = []
for i in range(1, len(s)):
    s[i] += s[i - 1]
h = [0 for i in range(101)]
for i in range(len(s)):
    g = 0
    if s[i] <= m:
        ans.append(0)
    else:
        posos = s[i] - m
        for j in range(100, -1, -1):
            if h[j] * j >= posos:
                ans.append((posos + j - 1) // j + g)
                break
            else:
                if h[j] > 0:
                    g += 1
                    posos -= h[j] * j

    h[sas[i]] += 1
print(*ans)
