n = int(input())
for i in range(n):
    temp = input().split(" ")
    temp[0] = int(temp[0])
    temp[1] = int(temp[1])
    temp[2] = int(temp[2])

    p1 = min(temp[0], temp[1], temp[2])
    temp.remove(p1)
    p2 = min(temp[0], temp[1])
    temp.remove(p2)
    num = temp[0]

    diff = p2 - p1
    num = num - diff
    print(p2 + num // 2)

    