from math import ceil

for x in range(int(input())):
    n, w = map(int, input().split())
    weights = list(map(int, input().split()))
    kek = ceil(w / 2)
    ans = []
    bag = 0
    for i in range(n):
        if weights[i] <= w:
            if weights[i] >= kek:
                ans = [i + 1]
                bag = weights[i]
                break
            else:
                ans.append(i + 1)
                bag += weights[i]
                if bag >= kek:
                    break
    if bag > kek:
        print(len(ans))
        print(" ".join(str(i) for i in ans))
    else:
        print(-1)