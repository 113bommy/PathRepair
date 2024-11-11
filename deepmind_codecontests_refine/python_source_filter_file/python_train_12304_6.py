a, b = [int(i) for i in input().split()]

resA = '' + str(a)
resB = '' + str(b)

if a == b or a + 1 == b or (b == 1 and a == 9):
    if a == 0 and b == 1:
        print(99, 100)
    elif a == b:
        print(resA + '0', resB + '1')
    else:
        print(resA + '9', resB + '0')
else:
    print(-1)