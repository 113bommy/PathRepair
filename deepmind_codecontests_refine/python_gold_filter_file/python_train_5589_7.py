
l, r = input().split('.')

if l[-1] == '9':
    print('GOTO Vasilisa.')
elif int(r[0]) >= 5:
    print(int(l) + 1)
else:
    print(l)

