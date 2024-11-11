arr = [int(i) for i in input().split()]

q = arr[1]/arr[0]
d = arr[1] - arr[0]

if arr[2]/arr[1] == q and arr[3]/arr[2] == q:
    if int(arr[3]*q) == arr[3]*q:
        print(int(arr[3]*q))
    else:
        print(42)
elif arr[2]-arr[1]==d and arr[3]-arr[2] == d:
    print(arr[3]+d)
else:
    print(42)