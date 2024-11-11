t = int(input())
for i in range(t):
    n = int(input())
    monsters = list(map(int, input().split()))
    m = int(input())
    dct = {}
    lst = []
    now = 0
    index = 0
    for j in range(m):
        a, b = list(map(int, input().split()))
        if b > now or (b == now and dct[index][0] < a):
            index = j
            now = b
        dct[j] = [a, b]
        lst.append([a, j])
    lst.sort()
    sfx = []
    sfx.append([dct[lst[m - 1][1]][1], lst[m - 1][1]])
    for j in range(m - 2, -1, -1):
        result1, i1 = sfx[-1]
        i2 = lst[j][1]
        result2 = dct[i2][1]
        if result2 > result1:
            sfx.append([result2, i2])
        else:
            sfx.append(sfx[-1])
    days = 1
    count = 0
    endurance = now
    strength = dct[index][0]
    for j in range(n):
        if endurance == 0:
            endurance = now
            strength = dct[index][0]
            days += 1
            count = 0
        if lst[-1][0] < monsters[j]:
            days = -1
            break
        if monsters[j] > strength:
            left = -1
            right = m - 1
            while left + 1 < right:
                mid = (left + right) // 2
                if lst[mid][0] >= monsters[j]:
                    right = mid
                else:
                    left = mid
            nxt = sfx[m - right - 1][1]
            strength = dct[nxt][0]
            endurance = dct[nxt][1] - count
            if endurance <= 0:
                endurance = dct[nxt][1]
                days += 1
                count = 0
        count += 1
        endurance -= 1
    print(days)
