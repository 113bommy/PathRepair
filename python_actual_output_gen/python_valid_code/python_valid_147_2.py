t = int(input())
for i in range(t):
    n = int(input())
    curr = 1
    for j in range(n):
        l, r = map(int, input().split())
        if r > curr:
            if l <= curr:
                print(curr, end=' ')
                curr += 1
            else:
                print(l, end=' ')
                curr = l + 1
        else:
            print(0, end=' ')
    print()
