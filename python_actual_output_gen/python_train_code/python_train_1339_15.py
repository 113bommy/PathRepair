n = int(input())
array = list(map(int, input().split()))
array.sort()
array.reverse()


i = 1
frontSum = sum(array[0:i])
backSum = sum(array[1:])
while frontSum <= backSum:
    i += 1
    frontSum = sum(array[0:i])
    backSum = sum(array[1:])

print(i)