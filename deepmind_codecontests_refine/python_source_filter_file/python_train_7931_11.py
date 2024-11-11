
n = int(input())

for i in range(n):
    a = int(input())
    b = [int(b) for b in input().split()]
    b.sort()
    count = 0
    for j in range(a - 1):
        if b[j] - b[j + 1] == 1:
            count = count + 1
    if count > 0:
        print(2)
    else:
        print(1)
    