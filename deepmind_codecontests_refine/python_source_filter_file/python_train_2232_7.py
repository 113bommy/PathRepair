l1 = list(input().split())
l2 = input()
d = {}
calories = 0
for i in range(len(l1)):
    d[i+1] = l1[i]
print(d)
for i in range(len(l2)):
    index = int(l2[i])
    calories += int(d[index])
print(calories)

