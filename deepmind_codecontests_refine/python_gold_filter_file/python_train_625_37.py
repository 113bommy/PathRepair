a, b, c = map(int, input().split())
print(len([n for n in range(a, b + 1) if c % n == 0]))