s = input()
ans = ""
if s.startswith('http'):
    s = s[4:]
    ans = 'http://'
else:
    ans = "ftp://"
    s = s[3:]

if s.count('ru') > 1 and s.index('ru') == 0:
        x = s[1:].index('ru') + 1
else:
    x =  s.index('ru')


ans += s[:x] + '.' + 'ru'
s = s[x+2:]
ans += '/' + s

print(ans)


