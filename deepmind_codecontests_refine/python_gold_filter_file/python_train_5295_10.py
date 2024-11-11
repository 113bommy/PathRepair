a = list(input())
if a[0] == a[-1]:
    if len(a) % 2 == 1:
        print('Second')
    else:
        print('First')
else:
    if len(a) % 2 == 1: 
        print('First')
    else:
        print('Second')