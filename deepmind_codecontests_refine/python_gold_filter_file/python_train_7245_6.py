a = [['','','','','','','','','','','','','',''],['','','','','','','','','','','','','','']]
for i in range(10): a.append(list('  '+input()+'  '))
a.append(['','','','','','','','','','','','','',''])
a.append(['','','','','','','','','','','','','',''])
for i in range(2,12):
    for ii in range(2,12):
        if a[i][ii] == '.':
            a[i][ii] = 'X'
            toch = ii
            st = i
            kek = 0
            while a[st][toch] == 'X':
                toch += 1
                kek += 1
            toch = ii-1
            while a[st][toch] == 'X':
                toch -= 1
                kek += 1
            if kek >= 5:
                print('YES')
                exit()
            toch = ii
            kek = 0
            while a[st][toch] == 'X':
                st += 1
                kek += 1
            st = i-1
            while a[st][toch] == 'X':
                st -= 1
                kek += 1
            if kek >= 5:
                print('YES')
                exit()
            kek = 0
            st = i
            while a[st][toch] == 'X':
                toch += 1
                st += 1
                kek += 1
            toch = ii-1
            st = i-1
            while a[st][toch] == 'X':
                toch -= 1
                st -= 1
                kek += 1
            if kek >= 5:
                print('YES')
                exit()
            kek = 0
            toch = ii
            st = i
            while a[st][toch] == 'X':
                toch += 1
                st -= 1
                kek += 1
            toch = ii-1
            st = i+1
            while a[st][toch] == 'X':
                toch -= 1
                st += 1
                kek += 1
            if kek >= 5:
                print('YES')
                exit()
            a[i][ii] = '.'
else:
    print('NO')
