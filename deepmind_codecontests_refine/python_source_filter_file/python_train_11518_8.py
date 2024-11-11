a = [int(i) for i in input().split()]
a1 = [[a[(j * 4) + i] for i in range(4)] for j in range(6)]
ver = a1[0]
per = a1[1]
niz = a1[2]
lev = a1[3]
prav = a1[4]
zad = a1[5]
res = "NO"

if len(set(lev)) == 1 and len(set(prav)) == 1:
    per1 = (1 if per[1] == per[3] else 0)
    ver1  = (1 if ver[1] == ver[3] else 0)
    niz1 = (1 if niz[1] == niz[3] else 0)
    zad1 = (1 if zad[0] == zad[2] else 0)
    
    per2 = (1 if per[0] == per[2] else 0)
    ver2  = (1 if ver[0] == ver[2] else 0)
    niz2 = (1 if niz[0] == niz[2] else 0)
    zad2 = (1 if zad[1] == zad[3] else 0)
    if (per1 == ver2 and per[1] == ver[0]) and (ver1 == zad2 and zad[1] == ver[1]) and (zad1 == niz2 and zad[0] == niz[0]) and (niz1 == per2 and per[0] == niz[1]):
        res = "YES"
    elif (per1 == niz2 and per[1] == niz[0]) and (ver1 == per2 and per[0] == ver[1]) and (zad1 == ver2 and per[2] == ver[2]) and (niz1 == zad2 and zad[1] == niz[1]):
        res = "YES"
elif len(set(niz)) == 1 and len(set(ver)) == 1:
    per1 = (1 if per[0] == per[1] else 0)
    lev1  = (1 if lev[0] == lev[1] else 0)
    prav1 = (1 if prav[0] == prav[1] else 0)
    zad1 = (1 if zad[0] == zad[1] else 0)
    
    per2 = (1 if per[2] == per[3] else 0)
    lev2  = (1 if lev[2] == lev[3] else 0)
    prav2 = (1 if prav[2] == prav[3] else 0)
    zad2 = (1 if zad[2] == zad[3] else 0)
    if (per1 == lev2 and per[0] == lev[2]) and (lev1 == zad2 and zad[2] == lev[0]) and (zad1 == prav2 and zad[0] == prav[2]) and (prav1 == per2 and per[2] == prav[0]):
        res = "YES"
    elif (per1 == prav2 and per[0] == prav[2]) and (prav1 == zad2 and zad[2] == prav[0]) and (zad1 == lev2 and zad[0] == lev[2]) and (lev1 == per2 and per[2] == lev[0]):
        res = "YES"
elif len(set(per)) == 1 and len(set(zad)) == 1:
    ver1 = (1 if ver[2] == ver[3] else 0)
    lev1  = (1 if lev[3] == lev[1] else 0)
    prav1 = (1 if prav[0] == prav[2] else 0)
    niz1 = (1 if niz[0] == niz[1] else 0)
    
    ver2 = (1 if ver[0] == ver[1] else 0)
    lev2  = (1 if lev[2] == lev[0] else 0)
    prav2 = (1 if prav[1] == prav[3] else 0)
    niz2 = (1 if niz[2] == niz[3] else 0)
    if (ver1 == lev2 and ver[2] == lev[2]) and (lev1 == niz2 and niz[2] == lev[3]) and (niz1 == prav2 and niz[0] == prav[1]) and (prav1 == ver2 and ver[0] == prav[0]):
        res = "YES"
    elif (ver1 == prav2 and ver[2] == prav[1]) and (prav1 == niz2 and niz[2] == prav[0]) and (niz1 == lev2 and niz[0] == lev[2]) and (lev1 == ver2 and ver[0] == lev[3]):
        res = "YES"
if len(set(per)) == 1 and len(set(zad)) == 1 and len(set(niz)) == 1 and len(set(ver)) == 1 and len(set(lev)) == 1 and len(set(prav)) == 1:
    res = "NO"
print(res)
