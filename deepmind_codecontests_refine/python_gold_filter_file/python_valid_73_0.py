from sys import stdin
inp = stdin.readline

t = int(inp())

for _ in range(t):
    n = int(inp())
    arr = [int(x) for x in inp().split()]
    ans = arr[:]
    ans.sort()

    i = 0

    while True:
        if arr == ans:
            break

        if not i % 2:
            for j in range(n//2):
                if arr[2*j] > arr[2*j + 1]:
                    arr[2*j], arr[2*j+1] = arr[2*j+1], arr[2*j]
        else:
            for j in range(n//2):
                if arr[2*j + 1] > arr[2*j + 2]:
                    arr[2*j+2], arr[2*j+1] = arr[2*j+1], arr[2*j+2]

        i += 1

    print(i)
