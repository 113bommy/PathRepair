def is_prime(n):
    if n == 1:return False
    for i in range(2, 1 + int(pow(n, 0.5))):
        if n%i==0:return False
    return True
n = int(input())
if is_prime(n):print(1);print(n)
if is_prime(n - 2):print(2);print(2, n-2)
else:
    n -= 3
    for i in range(3, n // 2 + 1, 2):
        if is_prime(i) and is_prime(n - i):
            print(3)
            print(3, i, n - i);break