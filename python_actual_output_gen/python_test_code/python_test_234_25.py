n = input() 

flag = True
while True:
    if len(n) >= 3 and n[:3] == '114':
        n = n[3:]
    elif len(n) >= 2 and n[:2] == '14':
        n = n[2:]
    elif n[0] == '1':
        n = n[1:]
    else:
        flag = False
        break
    if n == '': break

print('YES' if flag else 'NO')
