k = [int(x) for x in input().split()]
ans = 1

if k.count(2) >= 2 or k.count(2) == 1 and k.count(4) == 2 or k.count(1) > 0 or k.count(3) == 3:
    ans -= 1

print('YNEOS'[ans::2])
