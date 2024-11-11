code = '<3'.join([''] + [input() for _ in range(int(input()))] + [''])
SMS, i = input(), 0

for ch in code:
    i = SMS.find(ch, i)
    if i < 0:
        print('no')
        break
else:
    print('yes')