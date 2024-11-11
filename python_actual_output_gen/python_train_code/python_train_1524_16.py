
for _ in range(int(input())):
    n = int(input())
    arr = set(map(int, input().split()))
    if len(arr) > 1:
        print(1)
    else:
        print(len(arr))