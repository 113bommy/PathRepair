n = int(input())
for v in range(2, n):
    if n % v == 0:
        print(v, n//v, sep = '')
        break