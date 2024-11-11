n = str(eval(input()))
for x in n:
    for i in range(ord(x)):
        print('+', end = '')
    print('.')