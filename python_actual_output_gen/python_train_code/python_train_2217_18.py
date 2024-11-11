n = int(input())

rem = n % 10

if rem > 6:
    print(n+(10-rem))
else:
    print(n-rem)