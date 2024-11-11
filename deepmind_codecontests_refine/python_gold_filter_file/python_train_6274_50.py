t = int(input())

for _ in range(t):
    n = int(input())
    s = [int(i) for i in input().split()]
    for i in range(n-1, 0, -1):
        print(s[i], end=" ")
    print(s[0])