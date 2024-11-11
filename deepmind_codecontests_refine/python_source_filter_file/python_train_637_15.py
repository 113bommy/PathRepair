n = list(map(int, list(input().split())))
vect = [n[0], n[1]]

m = list(map(int, list(input().split())))
chest = []
for i in range(vect[0]-1):
    chest.append(m[i])

l = list(map(int, list(input().split())))
key = []
for i in range(vect[1]-1):
    key.append(l[i])
    
def check(li1,li2):
    codd = 0
    ceven = 0
    for foo in li1:
        if foo % 2 == 0:
            ceven += 1
        else:
            codd += 1
    kodd = 0
    keven = 0
    for foo in li2:
        if foo % 2 == 0:
            keven += 1
        else:
            kodd += 1

    c = min(codd,keven) + min(ceven,kodd)
    return c
print(check(chest,key))
