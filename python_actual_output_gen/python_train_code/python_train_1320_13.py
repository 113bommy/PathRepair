n = input()
s = input()
c0 = 0; c1 = 0
for i in s:
    if i == '0':
        c0 += 1
    else:
        c1 += 1
if c0 <= 1:
    print(s)
else:
    print('1' + '0' * c0)