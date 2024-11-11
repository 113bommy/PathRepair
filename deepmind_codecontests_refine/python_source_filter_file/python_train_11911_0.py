le = int(input())
integers = [int(i) for i in str(input()).split(" ")]
d = {}

for index, ele in enumerate(integers):  # should already be sorted
    if ele in d:
        d[ele].append(index)

    else:
        d[ele] = [index]

ans = []

for key, items in d.items():
    if len(items) == 1:
        ans.append((key, 0))
    else:
        shouldAdd = True
        prog = items[1] - items[0]
        for i in range(1, len(items), 1):
            if items[1] - items[0] != prog:
                shouldAdd = False
                break
        if shouldAdd:
            ans.append((key, prog))
print(len(ans))
for line in sorted(ans):
    print(line[0],line[1])

