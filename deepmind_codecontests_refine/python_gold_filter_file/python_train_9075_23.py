d = input()
if '4' in d or '7' in d:
    e=d.count('4')
    f=d.count('7')
    if e>=f:
        print('4')
    else:
        print('7')
else:
    print('-1')
