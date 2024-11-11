length = int(input())
arr = [int(x) for x in input().split()]
sorting_by = []
for num in range(length):
    for i in range(num+1,length):
        if arr[num] > arr[i]:
            sorting_by.append((arr[num], num + 1, i + 1))
sorting_by.sort()
# for pair in sorting_by:
#     print(pair[0],pair[1], pair[2])
# print("~~~~~~~~~~~~~~~")
sorting_by.sort(key=lambda x: -x[2])
print(len(sorting_by))
for pair in sorting_by:
    print(pair[0],pair[1], pair[2])
