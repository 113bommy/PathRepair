

N = int(input())
array = list(map(int, input().split()))
points = []
for i in range(N - 1):
    points.append((array[i], array[i+1]))
#print(points)
for i in points:
    for j in points:
        if i[0] < j[0] and j[1] > i[1] > j[0]:
            #print(i, j)
            print("yes")
            exit(0)
print("no")