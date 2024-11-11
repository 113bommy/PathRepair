t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split(" ")))
    curr = 0
    for i in arr:
        curr = max(0, curr + i)
    print("sol", curr)
