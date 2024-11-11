n, k = map(int, input().split())
tabs = list(map(int, input().split()))

finalTabs = []

for counter in range(2):
    clone = tabs.copy()
    for i in range(counter, n, k):
        clone[i] = 0
    finalTabs.append(clone)

output = 0
for element in finalTabs:
    e = element.count(1)
    s = element.count(-1)

    difference = abs(e - s)

    if difference > output:
        output = difference

print(output)