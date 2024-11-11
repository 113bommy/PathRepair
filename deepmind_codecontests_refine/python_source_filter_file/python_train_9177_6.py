n = int(input())
array = list(map(int, input().split(" ")))

for i in range(len(array)):
    if(array[i]>=0):
        array[i] = -array[i]-1

if(len(array)%2!=0):
    max_index = array.index(max(array))
    array[max_index] = -array[max_index]-1

print(*array)
