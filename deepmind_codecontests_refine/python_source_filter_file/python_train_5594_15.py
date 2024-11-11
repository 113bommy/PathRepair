n = input().split('.')

cel, drob = n[0], n[1]

if cel[-1] == '9': print('GOTO Vasilisa')
elif drob[0] < '5': print(cel)
else: print(int(cel)+1)