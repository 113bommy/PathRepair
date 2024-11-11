a = int(input())
if a % 4 == 2:
    print(1, 'B')
else:
    print((a - 1) % 4, 'A')