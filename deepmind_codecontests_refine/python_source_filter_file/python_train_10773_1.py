s = "1*" + input() + "*1"
ans = eval(s)
for i in range(2, len(s) - 1, 2):
    if s[i - 1] != '*': continue
    for j in range(i + 1, len(s) - 1, 2):
        if s[j + 1] != '*': continue
        ans = max(ans, eval(s[:i] + '(' + s[i: j] + ')' + s[j:]))
print (ans)
