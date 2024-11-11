N, A, B = map(int, input().split())

print('Alice' if (B - A + 1) % 2 == 0 else 'Borys')
