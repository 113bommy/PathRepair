n = int(input())
zoo = list(map(int, input().split()))

for _ in range(n):
    for i in range(n-1):
        if zoo[i] > zoo[i+1]:
            print(i, i+1)
            zoo[i], zoo[i+1] = zoo[i+1], zoo[i]
