n, digits = int(input()) // 2, list(map(int, input()))

print('YES' if set(digits) <= {4, 7} and
               sum(digits[:n]) == sum(digits[n:]) else 'NO')