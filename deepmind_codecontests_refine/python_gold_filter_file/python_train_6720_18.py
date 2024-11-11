n = int(input() )
a, b = 0, 0
for i in range(n):
    x, y = map(int, input().split() )
    a += x > y
    b += x < y

print('Mishka' if a > b else 'Chris' if a < b else 'Friendship is magic!^^')

