arr = input().split(" ")
n = int(arr[0])
button2 = int(arr[1])
start = 1
total = 0

for i in range(n):
    minutes = input().split(" ")
    firstMin = int(minutes[0])
    lastMin = int(minutes[1])
    totalBestMinutes = firstMin - lastMin + 1
    remainingMinutes = (firstMin - start) % button2
    total += totalBestMinutes + remainingMinutes
    start = lastMin + 1

print(total)