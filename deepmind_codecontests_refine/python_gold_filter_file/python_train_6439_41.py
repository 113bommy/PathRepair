a, b = map(int, input().split())

if a == b:
    print('Draw')
elif a == 1 or a > b != 1:
    print('Alice')
else:
    print('Bob')