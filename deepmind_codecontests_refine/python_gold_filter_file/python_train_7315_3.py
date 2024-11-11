t = int(input())

for case in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr2 = list(reversed(sorted(arr)))
    distinct = True
    for i in range(1, n):
        if (arr2[i] == arr2[i - 1]): distinct = False
    if (arr == arr2 and distinct):
        print("NO")
    else:
        print("YES")