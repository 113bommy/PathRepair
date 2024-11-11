s = input()

if s == 'zyxwvutsrqponmlkjihgfedcba':
    print(-1)
    exit()


if len(s)!=26:
    for i in range(26):
        if chr(97+i) not in s:
            print(s+chr(97+i))
            exit()
else:
    for i in range(25):
        if s[24-i]<s[25-i]:
            m = s[25-i]
            for x in s[25-1:]:
                if x > s[24-i]:
                    m = min(m, x)
            print(s[:24-i]+m)
            exit()
