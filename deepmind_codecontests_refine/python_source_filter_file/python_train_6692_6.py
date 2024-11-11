round = int(input())
for _ in range(round):
    test = int(input())
    if test < 10:
        print((10*(test-1)+1))
    if 10 < test < 100:
        mod = test // 10
        print((10*(mod-1)+3))
    if 1000 < test < 1000:
        mod = test // 100
        print((10*(mod-1)+6))
    if 1000 < test < 10000:
        mod = test // 1000
        print(10*mod)