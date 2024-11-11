s = list(input())
t = list(s[::-1])
for i in range(len(s)):
    if t[i] == 'b':
        t[i] = 'd'
    if t[i] == 'd':
        t[i] = 'b'
    if t[i] == 'p':
        t[i] = 'q'
    else:
        t[i] = 'p'
if s == t:
    print('Yes')
else:
    print('No')