import math
t = int(input())
for _ in range(t):
    n = int(input().strip())
    arr = list(map(int,input().strip().split()))
    minVal = min(arr)
    if minVal == 1:
        print("YES")
        continue
    arr2 = sorted(arr)
    f =True
    for i in range(n):
        if arr2[i] != arr[i] and math.gcd(arr[i],arr2[i])%minVal==0:
            f = False
            break
    if f:
        print("YES")
    else:
        print("NO")




