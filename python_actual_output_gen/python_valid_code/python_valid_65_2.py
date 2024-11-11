n = int(input())
print('71'[n & 1] + '1' * (n // 2 - 1))