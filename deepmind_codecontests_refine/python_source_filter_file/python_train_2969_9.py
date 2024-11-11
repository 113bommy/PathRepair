n, t, s = input().split()
if s == 'month':
    if n == '31':
        print(7)
    elif n == 30:
        print(11)
    else:
        print(12)
else:
    if n == '5' or n == '6':
        print(53)
    else:
        print(52)
