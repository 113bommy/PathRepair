i_osob = int(input())
osoby = [int(x) for x in input().split()]
osoby.sort()
czas, happy = 0, 0
for x in osoby:
    if czas <= x:
        happy += 1
    czas += x
print(happy)