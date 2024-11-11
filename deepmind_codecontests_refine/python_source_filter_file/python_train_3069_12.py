s=''

for i in range(0,8):
    s += input()

W = s.count('Q')*9 + s.count('R')*5 + s.count('B')*3 + s.count('K')*3 + s.count('P')
B = s.count('q')*9 + s.count('r')*5 + s.count('b')*3 + s.count('k')*3 + s.count('p')

if W==B:
    print('Draw')
else:
    print('White' if W>B else 'Black')
