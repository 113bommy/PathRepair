x, y, a, b = map(int, input().split())
print('Vasiliy' if b < x and a < x + y or a < y and b < x + y else 'Polycarp')