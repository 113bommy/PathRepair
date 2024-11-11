s = input()
#s = "1*" + s + "*1"
print(s)
n = len(s)
ans = eval(s)
for i in range (0, n // 2):
    if (i == 0 or s[i * 2 - 1] == '*'):
        for j in range (i + 1, n // 2 + 1):
            if (j == n // 2 or s[j * 2 + 1] == '*'):
                f = s[0 : i * 2] + '(' + s[i * 2: j * 2 + 1] + ')' + s[j * 2 + 1 : n]
            #print(i * 2, j * 2)
                #print(f)
                ans = max(ans, eval(f))
print(ans)
