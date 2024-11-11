g = ['a', 'e', 'i', 'o', 'u']

s = input()
t = input()

if len(s) != len(t):
    print('No')
else:
    for i in range(len(s)):
        if s[i] in g and t[i] not in g or s[i] in g and t[i] not in g:
            print('No')
            exit()
    print('Yes')
