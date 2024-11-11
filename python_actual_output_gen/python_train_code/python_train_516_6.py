s = input()
asogl = 'qwrtpsdfghjklzxcvbm'
g = 'qwrtpsdfghjklzxcvbmn'
r = True
for i in range(len(s) - 1):
    if s[i] in asogl:
        if s[i + 1] in g:
            r = False
if s[len(s) - 1] in asogl:
    r = False
if r:
    print('YES')
else:
    print('NO')