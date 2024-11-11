n = int(input())
towns = [int(x) for x in input().split()]
mv = towns[0]
mi = -1
mc = 0
for x in range(1,len(towns)):
    if towns[x] < mv:
        mv = towns[x]
        mi = x

print(mi+1 if towns.count(mv) == 1 else "Still Rozdil")