n = int(input())
if n == 1:
    print(0)
elif n % 2 == 0:
    print(int(n / 2) - 1)
else:
    print(n)