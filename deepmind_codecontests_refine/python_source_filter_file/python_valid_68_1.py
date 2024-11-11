a = int(input())
for i in range(a):
    num = float(input())
    x = num**0.5
    if x != int(x):
        x = int(x) + 1
    check = x**2
    if num == 2:
        print(1, 2)
        continue
    if check - num <= x:
        print(int(x), int(check - num + 1))
    else:
        dif = check - num
        print(int(2*x - 1 - dif), int(x))