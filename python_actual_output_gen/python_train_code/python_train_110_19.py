n, x, y = map(int, input().split())
num = input()
num = num[-x:]
num_1s = sum(map(int, num))
if num_1s == 0:
    print(1)
elif num[-(y + 1)] == 1:
    print(num_1s - 1)
elif num[-(y + 1)] != 1:
    print(num_1s + 1)
