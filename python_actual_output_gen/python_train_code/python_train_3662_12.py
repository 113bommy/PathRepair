n = int(input())
array = list(map(int, input().rstrip().split()))
array1 = list(set(array.copy()))
cnt,res = [],[]

for num in array1:
    cnt.append((num, array.count(num)))

for i in range(len(array1)):
    res.append([cnt[i][0], sum([pair[1] for pair in cnt[i+1:]])])
    if i == len(array1)-1:
        break

for x in array:
    if x != max(array1):
        print(res[array1.index(x)][1] + 1,end= ' ')
    else:
        print(1, end= ' ')




