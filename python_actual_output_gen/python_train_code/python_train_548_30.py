n=int(input())
blue=[input() for _ in range(n)]
bset = set(blue)

m=int(input())
red=[input() for _ in range(m)]

print(max([blue.count(b) - red.count(b) for b in bset]))
