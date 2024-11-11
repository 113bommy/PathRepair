from math import ceil

s = input()
a, b, c = map(int, input().split())  # initial
ca, cb, cc = map(int, input().split())  # costs
r = int(input())

na = s.count("B")
nb = s.count("S")
nc = s.count("C")

mini = 0
maxi = 2*r


def can(kol):
    ka, kb, kc = 0, 0, 0
    if na > 0:
        ka = ceil(kol*na-a)*ca
    if nb > 0:
        kb = ceil(kol*nb-b)*cb
    if nc > 0:
        kc = ceil(kol*nc-c)*cc
    return (max(ka, 0)+max(kb, 0)+max(kc, 0)) <= r


while mini < maxi:
    mid = (mini+maxi)//2
    mid += 1
    if can(mid):
        mini = mid
    else:
        maxi = mid-1

print(mini)