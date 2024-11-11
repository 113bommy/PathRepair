t = int(input())
for i in range(t):
    s = input()
    lst = []
    if 'X' in s:
        lst.append('1x12')
    for i in range(6):
        if s[i]==s[i+6]=='X':
            lst.append('2x6')
            break
    for i in range(4):
        if s[i]==s[i+4]==s[i+8]=='X':
            lst.append('3x4')
            break
    for i in range(3):
        if s[i]==s[i+3]==s[i+6]==s[i+9]=='X':
            lst.append('4x3')
            break
    for i in range(2):
        if s[i]==s[i+2]==s[i+4]==s[i+6]==s[i+8]=='X':
            lst.append('6x2')
            break
    if 'O' not in s:
        lst.append('12x1')
    print(len(lst),*lst)