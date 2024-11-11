n = int(input())
for i in range(n):
    m = int(input())
    inp = [int(i) for i in input().split()]
    for j in range(m):
        if j % 2:
            if inp[j - 1] < 0 and inp[j] > 0 or inp[j - 1] > 0 and inp[j] < 0:
                print(-inp[j - 1], end=' ')
            else:
                print(inp[j - 1], end=' ')
        else:
            if inp[j - 1] < 0 and inp[j] > 0 or inp[j - 1] > 0 and inp[j] < 0:
                print(inp[j + 1], end=' ')
            else:
                print(-inp[j + 1], end=' ')
    print()
