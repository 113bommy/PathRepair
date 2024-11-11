n = int(input())

p1 = input().strip().split()
p1 = [int(i) for i in p1[1:]]
p2 = input().strip().split()
p2 = [int(i) for i in p2[1:]]
comb = set()
cont = 0

while(True):

    if (tuple(p1+p2) in comb):
        print(-1)
        break
    if len(p1) == 0:
        print(cont, 2)
        break
    if len(p2) == 0:
        print(cont, 1)
        break

    cont += 1
    comb.add(tuple(p1+p2))
    p1_card = p1.pop(0)
    p2_card = p2.pop(0)

    if p2_card < p1_card:
        p1 += [p2_card, p1_card]

    else:
        p2 += [p1_card, p2_card]
