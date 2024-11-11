while True:
    try:
        l = list(map(int, input().split(',')))
    except:
        break
    d = sum(l[:10]) * l[10] / (l[10] + l[11])
    for i in range(10):
        if sum(l[:i]) >= d:
            break
    print(i)