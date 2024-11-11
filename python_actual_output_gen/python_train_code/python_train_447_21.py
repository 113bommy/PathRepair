nxy = [int(i) for i in input().split()]
n = nxy[0]
x = nxy[1]
y = nxy[2]
arr = [int(i) for i in input().split()]
i = 0
while arr[i]> min(arr[max(0, i - x): i + y]):
    i+=1
print(i+1)