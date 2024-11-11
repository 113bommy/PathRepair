import sys

input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())

import math

s = input().rstrip()

c2 = math.ceil(len(s) / 3)
op1 = ("abc" * c2)[:len(s)]
op2 = ("acb" * c2)[:len(s)]
op3 = ("cab" * c2)[:len(s)]
op4 = ("cba" * c2)[:len(s)]
op5 = ("bac" * c2)[:len(s)]
op6 = ("bca" * c2)[:len(s)]

l = [op1, op2, op3, op4, op5, op6]

prefsumsmodels = []
#
# prefsums1model = []
# prefsums2model = []
# prefsums3model = []
# prefsums4model = []
# prefsums5model = []
# prefsums6model = []

for op in range(6):
    model = []
    for i in range(n):
        if l[op][i] != s[i]:
            model.append(1)
        else:
            model.append(0)

    prefsumsmodels.append(model)

prefsums = []
for model in prefsumsmodels:
    ps = [0]

    for i in range(n):
        ps.append(ps[i] + model[i])

    prefsums.append(ps)


for tc in range(m):

    l, r = map(int, input().split())

    ans = 10**18

    for i in prefsums:
        changes = i[r] - i[l-1]

        ans = min(ans, changes)

    #abc acb cab cba bac bca

    # subs = s[l-1:r]
    #
    # c1 = math.ceil(len(subs) / 3)
    #
    # op1 = ("abc" * c1)[:len(subs)]
    # op2 = ("acd" * c1)[:len(subs)]
    # op3 = ("cab" * c1)[:len(subs)]
    # op4 = ("cba" * c1)[:len(subs)]
    # op5 = ("bac" * c1)[:len(subs)]
    # op6 = ("bca" * c1)[:len(subs)]
    #
    #
    #
    # ans = 10**18
    #
    # for op in l:
    #     diff = 0
    #     for i in range(len(subs)):
    #         if subs[i] != op[i]:
    #             diff += 1
    #
    #     ans = min(ans, diff)

    print(str(ans) + '\n')


