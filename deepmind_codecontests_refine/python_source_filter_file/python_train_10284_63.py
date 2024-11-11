k = int(input())
a, b  = map(int, input().split())
print('OK' if a<=b//k*k else 'NO')