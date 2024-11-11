trial = int(input())
for t in range(trial):
    housecnt,elec = (int(n) for n in input().split(" "))
    house = [int(n) for n in input().split(" ")]
    maxlist = []
    for h in range(housecnt-1):
        maxlist.append(house[h+1]-house[h])
    maxlist.sort()
    for p in range(min(housecnt,elec-1)):
        maxlist.pop()
    print(sum(maxlist))