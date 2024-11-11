inputs = list(map(int, input().split()))
n = inputs[0]
m = inputs[1]
k = inputs[2]
houses = list(map(int, input().split()))
# 10 meters between houses

distance = (n - 1) * 10


for i in range(0, n):
    if i != m and houses[i] > 0 and houses[i] <= k:
        part_dist = abs(m - 1 - i) * 10
        if part_dist < distance:
            distance = part_dist

print(distance)