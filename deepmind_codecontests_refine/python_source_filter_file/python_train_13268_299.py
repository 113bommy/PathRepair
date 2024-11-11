n = int(input())
occupancy_count = 0
for x in range(n):
    string = list(map(int,input().split()))
    if (string[1] - string[0]) > 2:
        occupancy_count+=1
print(occupancy_count)