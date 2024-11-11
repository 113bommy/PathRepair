categories = {
    0: 'D',
    2: 'C',
    3: 'B',
    1: 'A'
}
x = int(input())
category = x % 4
if category == 0:
    print('1 A')
elif category == 1:
    print('0 A')
elif category == 2:
    print('1 B')
else:
    print('0 A')
