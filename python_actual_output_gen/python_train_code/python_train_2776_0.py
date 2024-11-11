n, a, b = list(map(int, input().split(' ')))
seals = []
for x in range(n):
    seals.append(list(map(int, input().split(' '))))
maxt = 0
ls = [a, b]
def condition(x, y):
    for i in [0, 1]:
        for j in [0, 1]:
            for k in [0, 1]:
                if x[i]+y[j] <= ls[k] and x[1-i] <= ls[1-k] and y[1-j] <= ls[1-k]:
                    return True
    return False
for x in seals:
    for y in seals:
        if x != y and condition(x, y):
            total = x[0]*x[1] + y[0]*y[1]
            maxt = max(maxt, total)
print(maxt)
