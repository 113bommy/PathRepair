k = int(input().strip())

for _ in range(k):
    _, _, _, d = list(map(int, input().strip().split(" ")))
    print("%s %s %s" % (d, d, d))
