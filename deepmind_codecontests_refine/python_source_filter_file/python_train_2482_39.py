import re
Sp = input().replace('?','.')
T = input()
flag = 0
for i in range(len(Sp)-len(T)+1):
    if re.match(Sp[i:i+len(T)],T):
        Sp = Sp[:i-1]+T+Sp[i+len(T):]
        flag = 1
        break
if flag == 1:
    print(Sp.replace('.','a'))
else:
    print('UNRESTORABLE')
