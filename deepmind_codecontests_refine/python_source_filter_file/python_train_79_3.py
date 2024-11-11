A, B = [int(n) for n in input().split()]
print(A*B if 1 <= (A and B) <= 9 else -1)