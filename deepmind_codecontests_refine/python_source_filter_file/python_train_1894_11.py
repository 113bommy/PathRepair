n = int(input())
tmp = [1024, 512, 256, 128, 64, 32, 16, 8, 4, 2]
for i in range(n):
    request, number = int(input()), list(map(int, input().split()))
    if sum(number) < 2048:
        print("NO")
    else:
        while True:
            flag = 0
            if 2048 in number:
                print("YES")
                break
            for k in tmp:
                if k in number:
                    n1 = number.pop(number.index(k))
                    if k in number:
                        n2 = number.pop(number.index(k))
                        number.append((n1 + n2))
                        flag = 1
                    else:
                        number.append(n1)
            if flag == 0:
                print("NO")
                break