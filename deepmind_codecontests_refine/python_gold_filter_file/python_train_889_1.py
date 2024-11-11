m = int(input().split(' ')[1])
arr = list(map(int,input().split(' ')))

sumArray = [arr[0]]
for n in range(1,len(arr)):
        sumArray.append(sumArray[n-1]+arr[n])

total_happiness = 0
while m>0:
    indices = list(map(int,input().split(' ')))
    if indices[0]-1==0:
        sum = sumArray[indices[1]-1]
    else:
        sum = sumArray[indices[1]-1]-sumArray[indices[0]-2]

    if sum > 0:
        total_happiness += sum
    m-=1

print(total_happiness)