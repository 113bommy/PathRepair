S = input()
if S.replace('A', '') == 'KIHBR' and S.count('AA') == 0 and S.count('KIH') == 1:
    print('Yes')
else:
    print('No')