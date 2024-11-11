k, n = map(int, input().split())
vol = 0
for i in range(k):
    if n <= 240 or 5 * (i + 1) + n <= 240:
        vol += 1
        n += 5 * (i + 1)
    else:
        break
    if n >= 240:
        break
print(vol)