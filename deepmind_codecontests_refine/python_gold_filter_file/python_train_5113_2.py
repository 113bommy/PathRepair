n, s = list(map(int, input().split()))
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
if arr1[0] == 0:
    print("NO")
    exit()
if arr1[s-1] == 1:
    print("YES")
    exit()
if arr2[s - 1] == 1:
    #arr2.reverse()
    #print(arr1, arr2)
    for m in range(s, n):
        if arr1[m] == 1 and 1 == arr2[m]:
            print("YES")
            exit()
print("NO")
