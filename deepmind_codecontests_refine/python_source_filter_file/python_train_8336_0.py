numbers = int(input())
numberCount = {}
twoPower = []
i = 1
while i <= 10**9:
    twoPower.append(i)
    i *= 2
for i in list(map(int, input().split(" "))):
    if i in numberCount:
        numberCount[i] += 1;
    else:
        numberCount[i] = 1;
deleted = 0;
for i in numberCount.keys():
    hasCounter = False
    for j in twoPower:
        if (j - i) in numberCount and (j - i != i or numberCount.get(j - i) > 1):
            hasCounter = True
            break
    if not hasCounter:
        deleted += numberCount.get(i)
print(deleted)