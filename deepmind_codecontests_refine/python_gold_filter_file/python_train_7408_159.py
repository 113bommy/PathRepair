n = int(input())

if n % 2 == 1:
    print(0)
    exit()
else:
    print(2**(n//2))