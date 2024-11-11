

walls, chips = list(map(lambda x: int(x), input().split(' ')))

each = 0
for k in range(1, walls + 1):
    each += k

remain = chips % each

for k in range(1, walls):
    if remain - k > 0 :
        remain -= k
        continue
    elif remain - k == 0:
        print(0)
        break
    else:
        print(remain)
        break



