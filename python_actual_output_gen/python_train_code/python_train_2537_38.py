num_oranges, max_size, volume_glass = map(int, input().split())
oranges = list(map(int, input().split()))
full_glass = 0
origin_glass = volume_glass
index = 0
for index in range(num_oranges):
    if(max_size >= oranges[index]):
        volume_glass -= oranges[index] 
        if(volume_glass < 0):
            volume_glass += origin_glass
            full_glass += 1
print(full_glass)