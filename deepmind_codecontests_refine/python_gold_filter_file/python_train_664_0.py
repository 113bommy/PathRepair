code = '<3'.join([''] + [input() for _ in range(int(input()))] + [''])
SMS, i = input(), 0

for ch in code:
    i = SMS.find(ch, i) + 1
    if i < 1:
        print('no')
        break
else:
    print('yes')