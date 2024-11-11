n = int(input())

groupA = [0] * n
groupB = [0] * n

for i in range(n):
    groupA[i], groupB[i] = map(int, input().split())

groupAChoices = [0] * n
groupBChoices = [0] * n

k = n // 2
for i in range(k):
    groupAChoices[i] = 1
    groupBChoices[i] = 1

for i in range(1,n):
    if(groupA[i] < groupB[n-i-1]):
        groupAChoices[i] = 1
    if(groupB[i] < groupA[n-i-1]):
        groupBChoices[i] = 1

for i in range(n):
    print(groupAChoices[i], end="")
print()
for i in range(n):
    print(groupBChoices[i], end="")
