n, k = map(int, input().split())
s = input()
l = [0] * (k * 2 + 1)
c = '1'
p = 0
ret = 0
for i in range(len(s)):
    if s[i] != c:
        ret = max(ret, i - l[p])
        l.append(i)
        if c == '1':
            p += 2
        c = s[i]
ret = max(ret, n - l[p])
print(ret)
