s = input()
n = input()
l = len(s)
jud = True
new = ''
for i in range(l):
    if s[i] == n[i]:
        new += '0'
    else:
        if jud:
            new += s[i]
        else:
            new += n[i]
    jud = not jud
if jud:
    print(new)
else:
    print('impossible')