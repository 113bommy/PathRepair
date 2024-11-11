getInputList = lambda : list(input().split())
getInputIntList = lambda : list(map(int,input().split()))

n ,k = getInputIntList()
arr = getInputIntList()
arr1 = getInputIntList()

sleep_arr = [0] * n
s = 0
for i in range(n):
    if arr1[i] == 1:
        s += arr[i]
    else:
        sleep_arr[i] = arr[i]

#print(sleep_arr)
pre_sum = [0]

for i in sleep_arr:
    pre_sum.append(pre_sum[len(pre_sum)-1]+i)

m = -1
for i in range(n - k + 1):
    ps = pre_sum[i+k] - pre_sum[i] 
    if ps + s > m:
        m = ps + s

if m == -1:
    print(s+pre_sum[len(pre_sum)-1])
else:
    print(m)

