a, b, c = map(int, input().split())

if b > c + a:
    print('-')
elif a > b + c:
    print('+')
elif a < b + c:
    print('?')
elif b < a + c:
    print('?')
else:
    print('0')

