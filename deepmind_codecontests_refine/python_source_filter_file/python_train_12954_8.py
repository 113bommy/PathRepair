temparr = input()
temparr = temparr.split()
n = int(temparr[0])
k = int(temparr[1])
half = n // 2 
#print(half)
if half > k:
    print("-1")
elif n == 1 and k == 1:
    print(-1)
elif n == 1:
    print(-1)
elif half == k :
    cur = 1
    arr = []
    for i in range(1, n + 1):
        arr.append(str(i))
    print(" ".join(arr))
else:
    diff = 1 + k - half
    arr = []
    arr.append(str(diff))
    arr.append(str(diff * 2))
    diff2 = diff * 2
    for i in range(1, n -1):
        diff2 += 1 
        arr.append(str(diff2))
    print(" ".join(arr))
        
        
        
        