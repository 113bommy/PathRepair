q = int(input())
for _ in range(q):
    n = int(input())
    a = sorted([int(i) for i in input().split()])
    k = -1
    for i in a:
        if i - k == 1:
            print(2)
            break
        k = i
    else:
        print(1)
