input()
w = sorted([int(x) for x in input().split()])
tot = 0
good = 0
for i in range(len(w)):
    if tot <= w[i]:
        good += 1
    tot += w[i]
print(good)
