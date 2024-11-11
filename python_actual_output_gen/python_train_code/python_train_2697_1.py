s = input()
for i in range(len(s)):
    for j in range(97, 123):
        a = chr(j)
        t = s[:i] + a + s[i:]
        if t == t[::-1]: print(t); exit()
print('NA')
