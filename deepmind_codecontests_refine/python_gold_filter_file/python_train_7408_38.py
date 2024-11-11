n = int(input())
if n % 2 == 1:
    print(0)
else:
    nn = n // 2
    print(2**nn)