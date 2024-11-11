n = int(input())
arr = list(map(int, input().split()))

start = 0
prev = arr[0]
subarrays = []
for i, v in enumerate(arr):
    if i==0:
        continue
    if v <= prev:
        if i - start > 1:
            subarrays.append((start, i-1))
        start = i
    prev = v
i += 1
if i - start > 1:
    subarrays.append((start, i-1))
start = i


c_max = 0
for subarray in subarrays:
    c_max = max(c_max, subarray[1] - subarray[0] + 1)

for j in range(len(subarrays)-1):
    left = subarrays[j]
    right = subarrays[j+1]
    if right[0] == left[1]+1 and arr[right[0]+1] > arr[left[1]]:
        c_max = max(c_max, left[1]-left[0]+1 + right[1]-right[0])
    if right[0] == left[1]+1 and arr[right[0]] > arr[left[1]-1]:
        c_max = max(c_max, left[1]-left[0]+1 + right[1]-right[0])
print(c_max)
