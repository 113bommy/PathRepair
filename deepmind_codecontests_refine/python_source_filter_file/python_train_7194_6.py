n = int(input())

arr = [0] + [int(z) for z in input().split()] + [1001]
if n == 1:
    print(0)
    exit()
p = 1
finl = 0
while p < n:
    l = 0
    for i in range(p, n+1):
        if arr[i] == arr[i-1] + 1 and arr[i] == arr[i+1] - 1:
            l += 1
        else:
            break

    p += 1
    finl = max(finl, l)

print(finl)