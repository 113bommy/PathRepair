n, x = [int(c) for c in input().split()]

candies = []

for i in range(n):
    candies.append([int(c) for c in input().split()])



candies.sort(key=lambda x: x[2],reverse=True)

def find_best(candies, x, step):
    for i in range(len(candies)):
        if candies[i][0] == step and candies[i][1] <= x:
            return i

    return -1

eated = [0, 0]

for startWith in range(2):
    step = startWith
    c1 = candies[:]
    tmp = find_best(c1, x, step)
    x1 = x
    while tmp != -1:
        eated[startWith] += 1
        x1 = x1 + c1[tmp][2]
        step = (step + 1) % 2
        c1.pop(tmp)
        tmp = find_best(c1, x1, step)

print(max(eated))