n = int(input())
for i in range(2, 2333):
    if n % i == 0:
        print(str(i) + str(n // i))
        break