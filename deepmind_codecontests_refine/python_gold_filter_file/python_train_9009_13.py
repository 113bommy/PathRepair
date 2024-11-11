from operator import mul

A = sorted(int(input()) for _ in range(int(input())))

print(sum(map(mul, A, reversed(A))) % 10007)