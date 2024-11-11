s = input()
if not s.count('0'):
    print(s[:1])
else:
    for i in range(len(s)):
        if s[i] == '0':
            print(s[:i]+s[i+1:])
            exit()
