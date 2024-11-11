f = lambda: 'ABC' in 2*(input()+input()[::-1]).replace('X', ' ')

print('NO' if f()^f() else 'YES')