for _ in range(int(input())):
    x = int(input())
    l = list(map(int, input().split()))
    c = 0
    for i in range(len(l)):
        for j in range(l[i]-i-2, len(l),l[i]):
            if l[i] * l[j] == i + 1 + j + 1:
                c = c + 1
    print(c)