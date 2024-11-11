from collections import Counter
n = int(input())
arr = []
arr.append(0)
arr.append(1)
res = []
i = 2

while arr[i-1] < n:
    arr.append(arr[i-1]+arr[i-2])
    
    i += 1
    
arr = list(set(arr))
mapp = Counter(arr)


if n in mapp:
        res.append(n)
        res.append(0)
        res.append(0)
if n not in mapp:       
    for i in arr:  
        if (n - i) in mapp:
            res.append(i)
            res.append(n-i)
            res.append(0)
            break

if res:
    print(*res)
else:
    print("I'm too stupid to solve this problem")
        
