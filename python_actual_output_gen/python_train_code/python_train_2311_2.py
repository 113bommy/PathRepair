n = int(input())
s = list(input())
ret = 0
i = 0
while i < n:
    if i & 1 == 0:
        j = i + 1
        while j < n and s[i] == s[j]:
            s[j] = ''
            j += 1
            ret += 1
        i = j
    else:
        i += 1
s = ''.join(s)
if len(s) & 1 == 1:
    ret += 1
    s = s[:-1]
print(ret)
print(s)