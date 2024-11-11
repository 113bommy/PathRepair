n, m = map(int, input().split())
won = {}
for _ in range(m):
    votes = [int(x) for x in input().split()]
    index = -1
    maxi = -1
    for i in range(len(votes)):
        if(votes[i]>maxi):
            index = i+1
            maxi = votes[i]
    if index in won.keys():
        won[index] += 1
    else:
        won[index] = 1
index = -1
maxi = -1
for k in sorted(won.keys()):
    if(won[k] > maxi):
        maxi = won[k]
        index = k
print(index)
