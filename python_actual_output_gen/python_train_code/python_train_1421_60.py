


a, b, c, d = list(map(int, input().split()))
tmp1 = max(3 * a // 10, a - ((a // 250) * c))
tmp2 = max(3 * b // 10, b - ((b // 250) * d))
print('tie' if tmp1 == tmp2 else 'Misha' if tmp1 > tmp2 else 'Vasya')

#
# CodeForcesian
# ♥
# M ^ 2
