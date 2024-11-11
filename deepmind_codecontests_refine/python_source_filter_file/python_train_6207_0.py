n = int(input())

field = [[None] * n for _ in range(4)]

for i in range(0, n - 1, 2):
    if i > 0 and field[0][i - 1] == 'a':
        field[0][i] = field[0][i + 1] = 'b'
        field[1][i] = field[1][i + 1] = 'd'
    else:
        field[0][i] = field[0][i + 1] = 'a'
        field[1][i] = field[1][i + 1] = 'c'

for i in range(1, n - 1, 2):
    if i > 0 and field[2][i - 1] == 'e':
        field[2][i] = field[2][i + 1] = 'f'
        field[3][i] = field[3][i + 1] = 'h'
    else:
        field[2][i] = field[2][i + 1] = 'e'
        field[3][i] = field[3][i + 1] = 'g'

field[2][0] = field[3][0] = 'j'

if n % 2 == 0:
    field[2][n - 1] = field[3][n - 1] = 'i'
else:
    field[0][n - 1] = field[1][n - 1] = 'i'


for line in field:
    print(' '.join(line))
