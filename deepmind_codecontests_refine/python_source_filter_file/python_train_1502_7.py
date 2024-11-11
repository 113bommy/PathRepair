def check(num):
    remb = max(0, (num_b * num) - nb)
    rems = max(0, (num_s * num) - ns)
    remc = max(0, (num_c * num) - nc)
    moneyb = remb * pb
    moneys = rems * ps
    moneyc = remc * pc
    if (moneyb + moneys + moneyc) <= money:
        # print(123)
        return 1
    else:
        return 0


def binary_search(l, r):
    while l < r:
        mid = (l + r + 1) // 2
        # print(mid)
        if check(mid):
            l = mid
        else:
            r = mid - 1
    return l


s = input()
num_b = 0
num_s = 0
num_c = 0
for i in s:
    if i == "B":
        num_b += 1
    elif i == "S":
        num_s += 1
    elif i == "C":
        num_c += 1
nb, ns, nc = [int(i) for i in input().split()]
pb, ps, pc = [int(i) for i in input().split()]
money = int(input())
x = binary_search(0, 100000000000)
print(x)
