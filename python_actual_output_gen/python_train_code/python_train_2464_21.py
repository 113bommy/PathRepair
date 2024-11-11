n = int(input() )
a = list(map(int, input().split() ) )
x, y = a.count(5), a.count(0)
x = x // 9 * 9
print('5'*x + '0'*y if x else 0 if y else -1)
