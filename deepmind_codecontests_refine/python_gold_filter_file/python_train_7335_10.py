n = int(input())

a1 = []
a2 = []

sm1 = 0
sm2 = 0

for i in range(n):
    a = int(input())
    if a > 0:
        a1.append(a)
        sm1 += a
        last = 'first'
    else:
        a = abs(a)
        a2.append(a)
        sm2 += a
        last = 'second'

if sm1 == sm2:
    if a1 > a2:
        print('first')
    elif a2 > a1:
        print('second')
    else:
        print(last)
else:
    if sm1 > sm2:
        print('first')
    else:
        print('second')
