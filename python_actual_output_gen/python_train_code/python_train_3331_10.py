n = int(input())
points = list(map(int, input().split()))

unique_points = [0]
for element in points:
    if element not in unique_points and element != 0:
        unique_points.append(element)
print (len(unique_points))
    