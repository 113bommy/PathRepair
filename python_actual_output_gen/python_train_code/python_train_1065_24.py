a = ''

for i in range(8):
    a = a + input()

m = 9 * a.count('Q') + 5 * a.count('R') + 3 * (a.count('B') + a.count('K')) + a.count('P')
n = 9 * a.count('q') + 5 * a.count('r') + 3 * (a.count('b') + a.count('k')) + a.count('p')

if m > n:
    print('White')
elif m < n:
    print('Black')
else:
    print('Draw')