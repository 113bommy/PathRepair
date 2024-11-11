num = input()
num = eval(num)


while num > 0:
    num -= 1
    prefix = input()
    if prefix.endswith('po') :
        print('FILIPINO')
    elif prefix.endswith('mnida'):
        print('KOREAN')
    else:
        print('FILIPINO')


