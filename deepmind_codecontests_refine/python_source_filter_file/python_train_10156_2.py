s = input()

start = -1
end = -1
for i in range(len(s)):
    if s[i] != 'a':
        if start < 0:
            start = i
            end = i
        else:
            end = i
    if s[i] == 'a' and start > 0:
        break

if start < 0:
    print(s[0:len(s)-1], end="")
    print('z')
else:
    for i in range(len(s)):
        if start <= i <= end:
            if s[i] == 'a':
                print('z', end="")
            else:
                print(chr(ord(s[i]) - 1), end="")
        else:
            print(s[i], end="")



