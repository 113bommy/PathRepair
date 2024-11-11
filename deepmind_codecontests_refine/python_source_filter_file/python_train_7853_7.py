n = int(input())
data = list(map(int, input().split()))

maxx = max(data)
minn = min(data)

count_min = 0
count_max = 0

if minn == maxx:
    result = int((len(data) * (len(data) - 1))/2)
    print("{} {}".format(0, 1))
else:
    for d in data:
        if d == maxx:
            count_max+=1
        elif d == minn:
            count_min+=1

    diff = maxx - minn
    result = count_max * count_min

    print("{} {}".format(diff, result))