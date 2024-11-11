n, k, m = map(int,input().strip().split())

words = list(input().strip().split())

cost = list(map(int,input().strip().split()))
i = 1
se = {}
minset = {}
while i <= k:
    group = list(map(int,input().strip().split()))
    minv = 100000000
    for j in range(1,len(group)):
        curword = words[group[j]-1]
        currcost = cost[group[j]-1]
        if currcost < minv:
            minv = currcost
        se[curword] = i
    minset[i] = minv
    i+=1

msg = list(input().strip().split())

sum = 0
i = 0
while i < len(msg):
    curgp = se[msg[i]]
    sum += minset[curgp]
    i += 1
print(sum)

