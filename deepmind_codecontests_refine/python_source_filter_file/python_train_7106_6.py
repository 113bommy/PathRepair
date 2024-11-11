line = input().split(' ')
n = int(line[0])
m = int(line[1])
arr1 = []
line2 = input().split(' ')
for a in line2:
    arr1.append(int(a))
arr2 = []
line3 = input().split(' ')
for a in line3:
    arr2.append(int(a))
######################################
endpt = 2**9
ans = endpt
for i in range(endpt):
    count = 0
    for n1 in arr1:
        for n2 in arr2:
            if n1 & n2 == i:
                count += 1
                break
    if count == len(arr1):
        ans = i
        break
print(ans)