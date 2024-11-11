import math
s = input()
k = int(input())
if len(s) - 2 * (s.count('?') + s.count('*')) > k:
    print('Impossible')
    exit(0)
if len(s) - (s.count('?') + s.count('*')) == k:
    print(s.replace('?', '').replace('*', ''))
    exit(0)

if '*' in s:
    if 1 < len(s) - 2 * s.count('?') - s.count('*') < k:
        while '?' in s:
            find = s.find('?')
            s = s[:find - 1] + s[find + 1:]
        i = s.find('*')
        s = s.replace('*', '')
        s = s[:i] + s[i - 1] * (k - len(s)) + s[i:]
        print(s.replace('?', ''))
    else:
        while '?' in s and len(s) - s.count('?') - s.count('*') - 1 >= k:
            find = s.find('?')
            s = s[:find - 1] + s[find + 1:]
        while len(s.replace('*', '')) - 1 >= k and '*' in s:
            find = s.find('*')
            s = s[:find - 1] + s[find + 1:]
        print(s.replace('*', '').replace('?', ''))
else:
    # net ? in s
    while '?' in s and len(s.replace('?', '')) - 1 >= k:
        find = s.find('?')
        s = s[:find - 1] + s[find + 1:]
    if len(s.replace('?', '')) < k:
        print('Impossible')
    else:
        print(s.replace('?', ''))
