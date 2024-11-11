n, k = map(int, input().split())
s = input()
rev_s = s + s[::-1]
mido = "z" * n
for i in range(n + 1):
    if mido > rev_s[i:i + n]:
        mido = rev_s[i:i + n]
ind = float("inf")
for i in range(n):
    if mido[i] != mido[0]:
        if i < ind:
            ind = i
ans = ind * (2 ** min(k - 1, 100))
print((mido[0] * ans + mido[ind:ind + n - ans])[:n])