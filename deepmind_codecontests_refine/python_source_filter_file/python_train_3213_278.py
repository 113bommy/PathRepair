a, b, x = map(int, input().split())
print(b//x - a//x + (b%x == 0))