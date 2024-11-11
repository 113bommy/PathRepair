f=input()
s=input()
kb='qwertyuiopasdfghjkl;zxcvbnm,./'
if f=='R':
    for c in s:
        print(kb[kb.index(c)-1],end='')
else:
    for c in s:
        print(kb[kb.index(c)-1],end='')
