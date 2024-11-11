t = input()
if t[0] == 'h': ans, t = 'http://', t[4:]
else: ans, t = 'ftp://', t[3:]
k = t.find('ru')
ans += t[:k] + '.ru'
if len(t) > k + 2: ans += '/' + t[k + 2:]
print(ans)