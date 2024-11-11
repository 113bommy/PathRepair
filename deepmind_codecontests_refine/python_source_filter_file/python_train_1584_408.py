a = int(input())
print(*((3 + a, 3) if a % 2 else (2 + a, 2)))
