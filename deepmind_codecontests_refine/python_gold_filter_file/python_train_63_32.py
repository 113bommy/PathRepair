_, g = [int(x) for x in input().split()]
buckets = sorted([int(x) for x in input().split()])

for b in buckets[-1: :-1]:
    if g%b == 0:
        print(int(g/b))
        exit()
