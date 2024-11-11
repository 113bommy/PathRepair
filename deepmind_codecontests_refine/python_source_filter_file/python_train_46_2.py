n = int(input())
first = sorted(list(map(int, input().split())))
second = sorted(list(map(int, input().split())))
third = sorted(list(map(int, input().split())))


for i in range(len(second)):
    if first[i] != second[i]:
        print(first[i])
        break
else:
    print(first[-1])

for i in range(len(third) - 1):
    if second[i] != third[i]:
        print(second[i])
        break
else:
    print(second[-1])
