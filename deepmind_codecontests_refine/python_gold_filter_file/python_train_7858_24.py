input()
l = [int(x) for x in input().split()]
olde, ml, mg = l[0], 1, 1
for e in l[1:]:
    if olde <= e:
        ml += 1
    else:
        ml = 1
    mg = ml if ml > mg else mg
    olde = e
print(mg)
