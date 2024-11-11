s = input()
ind = s.find('.')

if s[ind-1] == '9':
    print('GOTO Vasilisa.')
else:
    if int(s[ind+1]) < 5:
        print(int(s[:ind]))
    else:
        print(int(s[:ind])+1)
