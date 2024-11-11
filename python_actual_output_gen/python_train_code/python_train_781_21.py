# https://codeforces.com/problemset/problem/599/A

dLeft, dRight, dShops = [int(i) for i in input().split(" ")]

minD = 2 * dLeft + 2 * dRight

if dLeft + dRight + dShops < minD:
    minD = dLeft + dRight + dShops
elif dLeft * 2 + dShops * 2 < minD:
    minD = dLeft * 2 + dShops * 2
elif dRight * 2 + dShops * 2 < minD:
    minD = dRight * 2 + dShops * 2

print(minD)
