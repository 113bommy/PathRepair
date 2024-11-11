a = input().split('.')
if a[0][-1] == '9':
    print('GOTO Vasilisa.')
else:
    if int(a[1][0]) > 4:
        print(a[0])
    else:
        print(int(a[0]) + 1)