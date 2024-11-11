lst = [int(item) for item in input().split()]
count = 0
newlst = [lst[0]]
for i in range(1,4):
    if lst[i] not in newlst:
        newlst.append(lst[i])
result = 4 - len(newlst)
print(result)
