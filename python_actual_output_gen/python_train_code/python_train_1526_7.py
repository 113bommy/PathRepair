t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    first_1 = arr.index(1)
    for i in range(n)[::-1]:
        if arr[i] == 1:
            last_1 = i
            break
    print(first_1, last_1)
    if first_1 == last_1:
        print(0)
    else:
        print(arr[first_1: last_1 + 1].count(0))