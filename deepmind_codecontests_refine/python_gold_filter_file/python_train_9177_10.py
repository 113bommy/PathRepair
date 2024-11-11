n = int(input())
array = list(map(int, input().split(" ")))

for i in range(len(array)):
    if(array[i]>=0):
        array[i] = -array[i]-1

if(len(array)%2!=0):
    min_index = array.index(min(array))
    array[min_index] = -array[min_index]-1

print(*array)
