n = int(input())
c = [-2] + [0] * n
p, q = 0, 0
for i in map(int, input().split()):
    if p < i:
        q = p
        p = i
        #c[p]-=1
    elif q < i:
        q = i
        c[p] += 1
print(c.index(max(c)))