cityNum = int(input())
cities = list(map(int, input().split()))

minValue = 1000000000
minIndex = 0
isStay = False

for i in range(0,len(cities)):
    if cities[i] < minValue :
        minValue = cities[i]
        minIndex = i
        isStay = False
    elif cities[i] == minValue:
        minIndex = i
        isStay = True

if isStay:
    print("Still Rozdil")
else:
    print(minIndex+1)
