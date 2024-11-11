
n, r = map(int, input().split(' '))

heaters = list(map(int, input().split(' ')))
heated = [0] * len(heaters)

heaters_cnt = 0
i = 0
while i < len(heated):
    flag = False
    for j in range(r-1, -r, -1):
        if heaters[max(0, min(i + j, n-1))] == 1:
            heaters_cnt += 1
            flag = True
            i = i + j + r
            break

    if not flag:
        heaters_cnt = -1
        break

print(heaters_cnt)