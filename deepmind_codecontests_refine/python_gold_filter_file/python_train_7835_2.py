t = int(input())
for _ in range(t):
    n = int(input())
    li = [int(i) for i in input().split()]
    if all([i == 0 for i in li]) or sum(li) == 0:
        print("NO")
    else:
        print("YES")
        k = 0
        for i in li:
            if i == 0:
                k += 1
        li = [i for i in li if i != 0]
        pos = [i for i in li if i > 0]
        neg = [i for i in li if i < 0]
        if sum(pos) > abs(sum(neg)):
            print(*pos, *neg, *[0] * k)
        else:
            print(*neg, *pos, *[0] * k)
