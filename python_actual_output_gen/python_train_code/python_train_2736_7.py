n = int(input())
n = n * n
if n <= 9:
    print(-1)
elif n % 4:
    print( n //2, n//2 + 1)
else:
    print(n//4 - 1, n // 4 + 1)
