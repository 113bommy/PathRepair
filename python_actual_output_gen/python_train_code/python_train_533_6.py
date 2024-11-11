n = int(input())
l = -10**9
r = 10**9
for i in range(n):
    s = input().split()
    x = int(s[1])
    if s[-1] == 'N':
        if s[0] == '<':
            s[0] = '>='
        elif s[0] == '<=':
            s[0] = '>'
        elif s[0] == '>':
            s[0] = '<='
        elif s[0] == '>=':
            s[0] = '<'
    if s[0] == '<':
        r = min(r, x - 1)
    elif s[0] == '<=':
        r = min(r, x)
    elif s[0] == '>':
        l = max(l, x + 1)
    elif s[0] == '>=':
        l = max(l, x)
if l > r:
    print('Impossible')
else:
    print(l)
        
        