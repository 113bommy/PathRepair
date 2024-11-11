n, dng, bus = map(int, input().split())
l = list(map(int, input().split())) + [3 * 10 ** 5]
res = 0
cont = 0
for i in l:
    if i <= dng:
        cont += 1
    else:
        if cont >= bus:
            a = cont - bus + 1
            res += a
        cont = 0
print(res)