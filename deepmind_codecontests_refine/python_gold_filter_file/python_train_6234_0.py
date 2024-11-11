b=False
while True:
    n = int(input())
    if n==0:break
    d=dict()
    if b:print()
    b=True
    for _ in range(n):
        line = input().split()
        tmp = int(line[1])*3+int(line[3]*1)
        if tmp in d:
            d[tmp].append(line[0])
        else:
            d[tmp] = []
            d[tmp].append(line[0])
    for k, vs in sorted(d.items(), key=lambda x: x[0])[::-1]:
        for v in vs:
            print('{0},{1}'.format(v, k))