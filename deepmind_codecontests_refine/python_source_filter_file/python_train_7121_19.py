#!/usr/bin/env python3
_ = input()
a = input()
x = a.count('5')
y = a.count('0')
if y == 0:
    ans = '-1'
elif x < 10:
    ans = '0'
else:
    ans = '5' * (x // 9 * 9) + '0' * y
print(ans)
