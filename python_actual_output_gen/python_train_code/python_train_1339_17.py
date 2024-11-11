n = int(input())
values = [int(n) for n in input().split()]

result = counter = 0

minimum = int(sum(values)/2) + 1
values_sort = (sorted(values))
array_iter = values[::-1]

for i in range(len(array_iter)):
    result += array_iter[i]
    counter += 1
    if (result >= minimum):
        break
        
print(counter)