s = input().strip()
n = len(s)
tail = [-1] * 26
f = [0] * n
for i in range(n):
    if s[i] == 'a':
        f[i] = 1
    else:
        f[i] = -int(1e9)
for i in range(n):
    x = ord(s[i]) - ord('a')
    for j in range(x + 1):
        if tail[j] != -1 and x <= f[tail[j]]:
            f[i] = max(f[i], f[tail[j]] + 1)
    tail[x] = i
# print(f)
ok = False
for i in range(n):
    if f[i] >= 26:        
        ok = True
        break
if not ok:
    print('-1')
    exit(0)
res = list(s)
len = 1
for i in range(n):
    if len > 26:
        break
    if f[i] == len:
        res[i] = chr(len - 1 + ord('a'))
        len += 1
print(''.join(map(str, res))) 
