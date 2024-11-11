def check(s, start, end, mp):
    if len(s) < len(start) + len(end):
        return 0
    for i in range(len(start)):
        if start[i] == '?':
            if mp.get(s[i], 0) != 1:
                return 0
        if start[i] != '?' and start[i] != s[i]:
            return 0
    for i in range(1, len(end) + 1):
        if end[-i] == '?':
            if mp.get(s[-i], 0) != 1:
                return 0
        if end[-i] != '?' and end[-i] != s[-i]:
            return 0
    for i in range(len(start), len(s) - len(end)):
        if mp.get(s[i], 0) == 1:
            return 0
    return 1


good = input()
template = input()
res = template.find('*')
if res != -1:
    x = template.split('*')
    start, end = x[0], x[1]
else:
    start = template
    end = ''
n = int(input())
x = {}
for i in good:
    x[i] = 1

for i in range(n):
    s = input()
    if res == -1 and len(s) > len(start) + len(end):
        print('NO')
    elif check(s, start, end, x):
        print('YES')
    else:
        print('NO')
