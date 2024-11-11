input()
s2 = input()
arr = s2.split(" ")
arr2 = []
for i in range(0, len(arr)):
    arr2.append(int(arr[i]))
arr2.sort()
num = 0
hp = 0
for j in range(0, len(arr2)):
    if num <= arr2[j]:
        hp = hp+1
    num += arr2[j]
print(hp)
