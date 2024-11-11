h,w = map(int,input().split())
a = [[i for i in input()] for _ in range(h)]
b = [x for in a if "#" in x]
c = zip(*[x for x in zip(*b) if "#"in x])
for d in c:
    print("".join(d))