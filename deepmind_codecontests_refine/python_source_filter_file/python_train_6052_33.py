s = input()
ver = False
horz = True
for i in range(len(s)):
    if s[i]=='0' and ver:
        ver = not ver
        print('1 1')
    elif s[i]=='0':
        ver = not ver
        print('3 1')
    elif s[i]=='1' and horz:
        horz = not horz
        print('4 3')
    else:
        horz = not horz
        print('4 1')