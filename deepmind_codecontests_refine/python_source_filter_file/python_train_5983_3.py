n, p = map(int, input().split())
s = input()
mid = n // 2 - 1
p -= 1
if p > mid:
    s = s[::-1]
    p = n - p + 1 
    
l = -1
r = -1
i = p
res = 0
while i >= 0:
    if s[i] != s[n - i - 1]:
        l = i
        diff = min(abs(ord(s[i]) - ord(s[n - i - 1])), 26 - abs(ord(s[i]) - ord(s[n - i - 1])))
        res += diff
    i -= 1
i = p 
while i <= mid:
    if s[i] != s[n - i - 1]:
        r = i
        diff = min(abs(ord(s[i]) - ord(s[n - i - 1])), 26 - abs(ord(s[i]) - ord(s[n - i - 1])))
        res += diff
    i += 1

if l == -1 and r == -1:
    print(0)
else:
    if r == -1:
        r = p
    if l == -1:
        l = p
    if p - l < r - p:
        res += 2 * (p - l)
        res += r - p
    else:
        res += (p - l)
        res += 2 * (r - p)
    print(res)
        