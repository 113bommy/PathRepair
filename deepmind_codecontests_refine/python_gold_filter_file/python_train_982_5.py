def add1(array, base):
    array[-1] += 1
    array = [0] + array
    k= len(array)-1
    while array[k]>=base:
        array[k] -= base
        array[k-1] += 1
        k -= 1
    if array[0] == 0:
        return array[1:]
    return array


n, k, d = list(map(int, input().split(' ')))
if n == 1:
    for i in range(d):
        print(1)
    quit()
if n > k**d:
    print("-1")

    quit()
arr = []
array = [0]*d
for i in range(n):
    arr.append(array)
    array = add1(array[:], k)

new = [[0]*len(arr) for _ in range(len(arr[0]))]
for i in range(len(arr)):
    for j in range(len(arr[0])):
        new[j][i] = arr[i][j]+1

for i in new:
    print(' '.join([str(x) for x in i]))
