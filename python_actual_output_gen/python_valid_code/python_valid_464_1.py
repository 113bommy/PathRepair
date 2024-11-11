a = [1, -1, -4, 0, 5, -8, 0, 9,]
for i in range(int(input())):
    x0, n = [int(num) for num in input().split(" ")]
    distance = 0
    if n % 4 == 0:
        distance = 0
    elif n % 4 == 2:
        distance = -1
    if n % 4 == 1:
        distance = n
    else:
        distance = -n - 1
    if x0 % 2 == 1:
        print(distance + x0)
    else:
        print(-distance + x0)

