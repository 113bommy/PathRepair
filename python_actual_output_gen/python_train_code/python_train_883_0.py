def getInput():
    return [sum([int(ele) for ele in rang]) for rang in input().replace(' ', '').split('0')]

n, m, k = list(map(int, input().split()))
recs = [(i+1, int(n / (i + 1))) for i in range(int(n ** 0.5)) if n % (i + 1) == 0]
recs += [(p[1], p[0]) for p in recs if p[1] != p[0]]

a = getInput()
b = getInput()

print(sum([sum([mp - x + 1 for mp in b if (mp - x) > -1]) * sum([np - y + 1 for np in a if (np - y) > -1]) for x, y in recs]))