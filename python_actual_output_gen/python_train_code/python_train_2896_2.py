from itertools import compress
arr = []
yo = len
for i in range(int(input())):
    #speed,ram,hdd,cost = map(int, input().split())
    k = tuple(map(int, input().split()))
    arr.append(k)

check = [True]*yo(arr)    
for i in range(yo(arr)):
    for j in range(yo(arr)):
        if arr[i][0]<arr[j][0] and arr[i][1]<arr[j][1] and arr[i][2]<arr[j][2]:
            check[i] = False
            
lis = list(compress(arr,check))
lis.sort(key = lambda x:x[-1])
print(arr.index(lis[0]))