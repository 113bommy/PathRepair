for _ in range(int(input())):
    a = int(input())
    twos = round(a / 3)
    ones = a - twos*2
    print(ones, twos)