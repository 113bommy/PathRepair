s = input()
s2 = ''
alp = 'aeiou'
i = 0
flag = 0
while i < len(s):
    if alp.find(s[i]) != -1:
        s2 += s[i]
        i += 1
        flag = 0
    else:
        flag += 1
        if flag == 3:
            if s[i - 2] == s[i - 1] and s[i] == s[i - 1]:
                s2 += s[i]
                flag -= 1
                i += 1
            else:
                s2 += ' '
                flag = 0
        else:
            s2 += s[i]
            i += 1
print(s2)