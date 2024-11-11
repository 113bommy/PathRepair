n = int(input())
array = [int(c) for c in input().split()]

steps = array[0]
for i in range(1, n):
    steps += abs(array[i] - array[i-1])

print(steps)