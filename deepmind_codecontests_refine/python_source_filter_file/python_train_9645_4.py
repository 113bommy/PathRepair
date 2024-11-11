n = int(input())
nb = list(map(int, input().split()))
distinct = []
for i in nb:
    if i and i not in distinct:
        distinct.append(i)

print(distinct)