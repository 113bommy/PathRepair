n = [int(i) for i in input().split()]

batata = [1000]*(n[0])
score = [0]*(n[0])

for i in range(n[1]):
    all = [int(i) for i in input().split()]
    for b in range(all[0]-1, all[1]):
        if batata[b] > all[2]:
            batata[b] = all[2]
            score[b] = all[3]
sum = 0
for i in range(n[0]):
    sum += score[i]

print(sum)





