a, b, c, d = int(input()), int(input()), int(input()), int(input())
print(int( ((a ^ b) and (c or d)) ^ ((b and c) or (a ^ d))))
