s = input()
t = s.count('4')+s.count('7')
flag = 1
for i in str(t):
    if i != '4' and i != '7':
        flag = 0
        print('NO')
        break
if flag:print('YES')
