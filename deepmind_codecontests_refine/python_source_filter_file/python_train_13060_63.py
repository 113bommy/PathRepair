x = int(input())

a = x // 2
b = x - (x // 2)

if x % 2 == 0:
    print(f"{x - 2} {2}")
else:
    print(f"{x - 3} {3}")
