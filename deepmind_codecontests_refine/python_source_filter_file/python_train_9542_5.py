total, groups, message = [int(x) for x in input().split()]
s = [*map(str, input().split())]
# print(*s)
cost = [*map(int, input().split())]
price = dict()
for i in range(0, total):
    price[s[i]] = cost[i]

for i in range(0, groups):
    stringList = list(map(int, input().split()))
    groupSize = int(stringList[0])
    print(groupSize)
    mini = 10**9 + 1
    for ptr in range(0, groupSize):
        mini = min(mini, price[s[stringList[ptr + 1] - 1]])
    for ptr in range(0,groupSize):
        price[s[stringList[ptr + 1] - 1]] = mini
message = input()
res = 0
for x in list(message.split()):
    res += price[x]
print(res)