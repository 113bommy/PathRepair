items = int(input())
astr = input().split()
totalPercent = 0
for i in range(items):
    totalPercent += int(astr[i])
print(totalPercent / items)
