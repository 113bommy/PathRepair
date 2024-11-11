h, w = map(int, input().split(' '))
print(int(h * w / 2) + h * w % 2 if h > 1 and w > 1 else 0)