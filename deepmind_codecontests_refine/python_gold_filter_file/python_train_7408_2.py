n = int(input())
if n % 2 == 1 or n == 0:
    print(0)
else:
    print(2**(n//2))