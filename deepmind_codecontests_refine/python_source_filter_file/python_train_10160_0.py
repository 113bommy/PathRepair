line = [int(x) for x in input().split()]
rows = line[0]
cols = line[1]
k = line[2]
t = line[3]

waste = []
res = ["Carrots", "Kiwis", "Grapes"]

for case in range(k):
    waste.append([int(x) for x in input().split()])

for q in range(t):
    query = [int(x) for x in input().split()]
    foundWaste = False
    pre = 0
    for w in waste:
        if w[0] < query[0]:
            pre +=1 
        if w[0] == query[0]:
            if w[1] < query[1]:
                pre += 1
            elif w[1] == query[1]:
                foundWaste = True
                break
    if foundWaste:
        print("Waste")
    else: 
        print(res[((query[0]+1)*cols+query[1]-pre+1) % 3])


