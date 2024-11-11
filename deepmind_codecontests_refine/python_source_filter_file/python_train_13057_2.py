for i in range(int(input())):
    s = input()
    count = s.count('X')
    if count == 0:
        print(0)
    elif count == 12:
        print('6 1x12 2x6 3x4 4x3 6x2 12x1')
    else:
        lst = []
        if count >= 6:
            for i in range(2):
                if s[i] == s[i+2] == s[i+4] == s[i+6] == s[i+8] == s[i+10] == 'X':
                    lst.append( '6x2' )
                    break
        if count >= 4:
            for i in range(3):
                if s[i] == s[i+3] == s[i+6] == s[i+9] == 'X':
                    lst.append( '4x3' )
                    break
        if count >= 3:
            for i in range(4):
                if s[i] == s[i+4] == s[i+8] == 'X':
                    lst.append('3x4')
                    break
        if count >= 2:
            for i in range(6):
                if s[i] == s[i+6]:
                    lst.append('2x6')
                    break
        if count >= 1:
            lst.append( '1x12' )

        lst.sort()
        print(str(len(lst)) + ' ' + ' '.join(lst))