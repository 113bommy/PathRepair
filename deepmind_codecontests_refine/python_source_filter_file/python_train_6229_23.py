a, b = map(int, input().split())

white = '.' * 100
black = '#' * 100
wb = '.#' * 50

ban = []

num_b = b - 1
num_a = a - 1

gyo_b = num_b // 50
ret_b = num_b % 50

gyo_a = num_a // 50
ret_a = num_a % 50

for i in range(gyo_a):
    ban.append(wb)
    ban.append(white)

ban.append(('.#' * ret_a + ('..' * (50 - ret_a))))
ban.append(white)

for i in range(50 - 2 * (gyo_a + 1)):
    ban.append(white)

for i in range(50 - 2 * (gyo_b + 1)):
    ban.append(black)

for i in range(gyo_b):
    ban.append(wb)
    ban.append(black)

ban.append('.#' * ret_b + '##' * (50 - ret_b))
ban.append(black)

print(100, 100)

for item in ban:
    print(''.join(item))
