

n = int(input())
towns = [int(i) for i in input().split()]
best = 1e9 + 5
count = 0
index = 0
for i in range(n):
    town = towns[i]
    if (town < best):
        best = town
        count = 1
        index = i + 1
    elif (town == best):
        count += 1
if (count > 1):
    print ('Still Rozdil')
else:
    print (index)