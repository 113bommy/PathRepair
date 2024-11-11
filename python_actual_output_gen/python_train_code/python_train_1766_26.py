amount  = int(input())
array = [int(s) for s in input().split()]
counter = 0
i = 0
while i < len(array) - 2:
    if array[i] == 1 and array[i + 1] == 0 and array[i + 2] == 1:
        counter += 1
        i += 3
    i += 1
print(counter)