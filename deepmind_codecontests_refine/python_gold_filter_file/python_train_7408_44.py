n = int(input())
if n % 2 == 1:
    print(0)
else:
    n = n//2
    print(2**n)