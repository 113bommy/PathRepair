a, b, c = input().split()
if c == 'week':
    if a in ['6']:
        print(53)
    else:
        print(52)
else:
    if a == '31':
        print(7)
    elif a == '30':
        print(11)
    else:
        print(12)