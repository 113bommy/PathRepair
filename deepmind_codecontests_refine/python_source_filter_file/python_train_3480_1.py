#k, a, b, v = map(int, input().split())

k, a, b, v = 3, 10, 1, 3
rezult = 0


box = {
    'sep': 0,
    'place': 0,
    'nuts': 0
}

while a > 0:
    if b >= 0:
        if b < k:
            box['sep'] = b
            box['place'] = b+1
            b = 0
        elif b == 0:
            box['sep'] = 0
            box['place'] = 1
        else:
            box['sep'] = k - 1
            box['place'] = k
            b -= box['sep']
    if a < v * box['place']:
        box['nuts'] = a
        a = 0
    else:
        a -= (v * box['place'])
    rezult += 1

print(rezult)
