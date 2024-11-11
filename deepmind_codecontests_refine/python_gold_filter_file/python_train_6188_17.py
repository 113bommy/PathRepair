n, a, b = map(int, input().split())
print(*[((w * a) - (w * a) // b * b) // a for w in map(int, input().split())])