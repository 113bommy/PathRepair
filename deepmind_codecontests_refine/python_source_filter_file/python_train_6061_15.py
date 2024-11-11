t = int(input())
for j in range(t):
    n = int(input())
    number = []
    if n % 2 == 0:
        for i in range(int(n/2)):
            number.append(1)
    else:
        for i in range(int(n/2)-1):
            number.append(1)
        number.append(7)
    print(*number, sep="")