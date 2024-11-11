import sys
input = sys.stdin.readline

n = int(input())
cups = {}
cupLst = []
for i in range(n):
    cup = int(input())
    cupLst.append(cup)
    if cup in cups:
        cups[cup] += 1
    else:
        cups[cup] = 1

if len(cups) == 1:
    print("Exemplary pages.")
elif len(cups) == 2:
    tot = 0
    for cup in cups:
        tot += cups[cup]
    if tot > 2:
        print("Unrecoverable configuration.")
    elif (abs(cupLst[0]-cupLst[1])/2).is_integer():
        print(abs(cupLst[0]-cupLst[1])//2, f"ml. from cup #{1 if cupLst[0] < cupLst[1] else 2}"
        f" to cup #{1 if cupLst[1] < cupLst[0] else 2}.")
    else:
        print("Unrecoverable configuration.")
elif len(cups) == 3:
    sc = sorted(cups)
    if cups[sc[1]] != n-2 or sc[2]-sc[1] != sc[1]-sc[0]:
        print("Unrecoverable configuration.")
    else:
        print(sc[2]-sc[1], f"ml. from cup #{cupLst.index(sc[0]) + 1} to cup #{cupLst.index(sc[2]) + 1}.")
else:
    print("Unrecoverable configuration.")