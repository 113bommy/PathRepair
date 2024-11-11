s = input()
fl = False
for i in range(len(s) - 3):
    if s[i] != s[i + 1] and s[i + 1] != s[i + 2] and s[i] != s[i + 2] and s[i] != '.' and s[i + 1] != '.' and s[i + 2] != '.':
        print('Yes')
        break
else:
    print('No')