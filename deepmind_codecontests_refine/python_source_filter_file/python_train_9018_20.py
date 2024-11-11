x, y = map(int, input().split())

x = x - y + 1

print(['No', 'Yes'][(x, y) == (0, 1) or
                    x >= 0 and y > 0 and x % 2 == 0])
